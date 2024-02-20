 
class Solution{
public:

//   int solve(int i, int j ,string &str, bool check){
//       if(i>j){
//           return 0;
//       }
//       if(i==j){
//           if(check == true){
//               return str[i]=='T';
//           }
//           else{
//               return str[i]=='F';
//           }
//       }
//       int count = 0;
//       for(int k=i+1; k<j; k+=2){
          
//           int lt=solve(i,k-1,str,true);
//           int lf=solve(i,k-1,str,false);
//           int rt=solve(k+1,j,str,true);
//           int rf=solve(k+1,j,str,false);
//          if(str[k]=='&'){
//               if(check==true){
//                   count+=lt*rt;
//               }
//               else{
//                   count+=lf*rf+lf*rt+lt*rf;
//               }
//           }
          
//           else if(str[k]=='|'){
//               if(check==true){
//                   count+=lt*rt+lt*rf+lf*rt;
//               }
//               else{
//                   count+=lf*rf;
//               }
//           }
          
//           else if(str[k]=='^'){
//               if(check==true){
//                   count+=lt*rf+lf*rt;
//               }
//               else{
//                   count+=lt*rt+lf*rf;
//               }
//           }
//       }
//      return count%1003;
//   }
  

//   int countWays(int n, string str){
//       return solve(0,n-1,str,true);
//   }




  int t[201][201][2];
    int solve(string &s, int i, int j,bool state){
       
      if(i>j){
          return 0;
      }
      if(t[i][j][state]!=-1)  return t[i][j][state];
      
      if(i==j){
          if(state==true){
              return s[i]=='T';
          }
          else{
              return s[i]=='F';
          }
      }
          int count=0;
      for(int k=i+1;k<j;k+=2){
          
          int lt=solve(s,i,k-1,true);
          int lf=solve(s,i,k-1,false);
          int rt=solve(s,k+1,j,true);
          int rf=solve(s,k+1,j,false);
          
          if(s[k]=='&'){
              if(state==true){
                  count+=lt*rt;
              }
              else{
                  count+=lf*rf+lf*rt+lt*rf;
              }
          }
          
          else if(s[k]=='|'){
              if(state==true){
                  count+=lt*rt+lt*rf+lf*rt;
              }
              else{
                  count+=lf*rf;
              }
          }
          
          else if(s[k]=='^'){
              if(state==true){
                  count+=lt*rf+lf*rt;
              }
              else{
                  count+=lt*rt+lf*rf;
              }
          }
          
      }
       
      return  t[i][j][state]=count%1003;
    }
    int countWays(int N, string S){
          t[N+1][N+1][2];
          memset(t,-1,sizeof(t));
          return solve(S,0,N-1,true);
    }
};