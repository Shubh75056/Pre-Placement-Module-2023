public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strings =str.split(" ");
        if(pattern.length()!=strings.length) return false;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int last=0;
        for(int i=0;i<pattern.length();i++){
            if(map.containsKey(pattern.charAt(i))){
                int index = map.get(pattern.charAt(i));
                if(strings[i].compareTo(strings[index])!=0) return false;
            }else{
                if(!map.isEmpty() && strings[i].compareTo(strings[last])==0) return false;
                map.put(pattern.charAt(i),i);
                last =i;
            }
        }
        return true;
    }
}
