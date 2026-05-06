//Leetcode:3464. Maximize the Distance Between Points on a Square
//Working but giving TLE on case 611/619
class Solution {
public:
  
    long long convertToOneD(int x , int y , int side)
{
    // Bottom edge (0,0 → side,0)
    if(y == 0)
        return x;

    // Right edge (side,0 → side,side)
    else if(x == side)
        return side + y;

    // Top edge (side,side → 0,side)
    else if(y == side)
        return 3LL * side - x;

    // Left edge (0,side → 0,0)
    else
        return 4LL * side - y;
}

    
      bool isPossible(vector<long long>& arr2, int n, int k, long long D, long long perimeter) {
    for(int i = 0; i < n; i++) {
        int count = 1;
        long long first = arr2[i];
        long long last = arr2[i];

        int j = i + 1;   //  reset for each i

        while(j < i + n) {
            if(arr2[j] >= last + D) {
                count++;
                last = arr2[j];
            }

            if(count == k) {
                // circular check
                if(last - first <= perimeter - D)
                    return true;
                break;
            }
            j++;
        }
    }
    return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        
        int n=points.size();
       vector<long long> arr;
      
        vector<long long> arrdouble(2*n);
        for(int i =0;i<n;i++)
        {
            arr.push_back(convertToOneD(points[i][0] , points[i][1], side));
        }
        sort(arr.begin(), arr.end());
        long long perimeter = 4LL * side;
        for(int i =0;i<n;i++)
        {
            arrdouble[i]=arr[i];
            arrdouble[i+n]=arr[i]+perimeter;
        }


        long long low=0;
        long long high=side;
        long long ans=0;
        while(low<=high)
        {
            
            int mid =(low+high)/2;
            if(isPossible(arrdouble , n ,k,mid ,perimeter ))
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (int)ans;

        
    }
};



//Approach-2 (Binary Search + Optimised check)
//T.C : O(nlogn+log(side)⋅n⋅klogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    ll get1D(int side, int x, int y) {
        if(y == 0) return x;

        if(x == side) return side + y;

        if(y == side) return 3LL * side - x;

        return 4LL * side - y;
    }

    bool check(vector<ll>& doubled, int n, int k, int side, int mid) {
        ll perimeter = 4LL * side;

        for(int i = 0; i < n; i++) { //O(n)
            int count = 1; //Picked one point
            int idx   = i;

            ll lastPos = doubled[idx];

            for(int j = 2; j <= k; j++) { //O(k * log(n))
                ll target = lastPos + mid;

                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);

                if(it == begin(doubled) + i + n) break;

                idx = it - begin(doubled);
                lastPos = doubled[idx];
                count++;
            }

            if(count == k && (doubled[i] + perimeter - lastPos >= mid)) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ll perimeter = 4LL * side;
        int n = points.size();

        vector<ll> positions(n);

        for(int i = 0; i < n; i++) {
            positions[i] = get1D(side, points[i][0], points[i][1]);
        }

        sort(begin(positions), end(positions));

        //double the positions array to easily handle round wrap
        vector<ll> doubled(2*n);
        for(int i = 0; i < n; i++) {
            doubled[i]   = positions[i];
            doubled[i+n] = positions[i] + perimeter;
        }

        int l = 0;
        int r = 2*side;

        int result = 0;

        //log(side) * n * klog(n)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(doubled, n, k, side, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;


    }
};
