class Solution {
public:
    long long MOD = 1000000007;
    using ll =long long;
    long long power( ll a, ll b){
        if(b==0){
            return 1; //base case we divide the number recursively by 2 
        }
        long long half = power(a,b/2);

        half = (half*half)%MOD;

        if(b%2==1){
            return (half*a)%MOD;
        }

        return half ;
    }
    int countGoodNumbers(long long n) {
        long long even  = (n+1)/2;
        long long odd = n/2;
        
        long long ans =(power(5,even)*power(4,odd));

        return ans%MOD;
    }
};