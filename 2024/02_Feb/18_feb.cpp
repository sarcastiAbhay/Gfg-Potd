//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++; 
        }
        priority_queue<int> pq;
        for(auto i:arr){
            if(i!=0)
            pq.push(i);
        }
        while(k--){
            int a = pq.top();
            pq.pop();
            a--;
            pq.push(a);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top()*pq.top();
            pq.pop();
        }
        return sum;
    }
};