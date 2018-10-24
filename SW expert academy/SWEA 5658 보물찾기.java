import java.util.*;
public class Solution {
    public static int T;
    public static int N, K;
    public static int capacity;    //한 변의 길이 :N / 4
    
    public static char[] password = new char[28];
    public static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    public static ArrayList<Integer> list = new ArrayList<Integer>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int test_case = 1; test_case <= T; test_case++) {
            N = sc.nextInt();
            K = sc.nextInt();
            String str = sc.next();
            for(int i = 0; i < N; i++) 
                password[i] = str.charAt(i);
            capacity =N / 4;
            
            for(int i = 0; i < capacity ; i++ ) {    //회전 하는동안 나올 수 
                for(int j = 0; j < 4; j++) {
                    int num = 0;
                    for(int k = 0; k < capacity; k++) {
                        int temp = 0;
                        if(password[capacity * j + k] <= 57) temp = (int)password[capacity * j + k] - 48;
                        else temp = (int)password[capacity*j + k] - 55;
                        num += (int)Math.pow(16, capacity - 1 - k) * temp; 
                    }
                    map.put(num, 1);
                }
                char temp = password[N-1];
                for(int j = N-1; j > 0; j--) {
                    password[j] = password[j-1];
                }
                password[0] = temp;
            }
            Set set = map.keySet();
            Iterator it= set.iterator();
            
            while(it.hasNext()) {
                list.add((int)it.next());
            }
            Collections.sort(list);
            System.out.println("#" + test_case + " " + list.get(list.size()-K));
            list.clear();
            map.clear();
        }
    }
}