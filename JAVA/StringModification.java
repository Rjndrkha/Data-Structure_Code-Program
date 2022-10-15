class Solution
{
   public static String rearrangeString(String s)
   {
       //Your code here
       int n = s.length();
       int[] arr = new int[26];
       int maxIndex = 0;
       for(char it : s.toCharArray()) arr[it-'a']++;
           
        for(int i=1; i<26; i++) {
            if(arr[maxIndex]<arr[i]) maxIndex = i;
        }
       
       if(arr[maxIndex]>(n+1)/2) return "-1";
       
       char[] ans = new char[n];
       int index = 0;
       for(int i=0; i<arr[maxIndex]; i++) {
           ans[index] = (char) (maxIndex+97);
           index+=2;
       }
       
       arr[maxIndex] = 0;
       for(int i=0; i<26; i++) {
           if(arr[i] == 0) continue;
           
           for(int j=0; j<arr[i]; j++) {
               if(index>=n) index = 1;
               ans[index] = (char) (i+97);
               index+=2;
           }
       }
       
       return new String(ans);
   }
   
}
