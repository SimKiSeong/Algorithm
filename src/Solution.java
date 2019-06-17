class Solution {
    public int solution(int n, int maxhp, int[] times, int[] effects) {
        int answer = 0;
        int nowhp = 0;
        int curtime = 0;
        int counter = 0;
        int noweffects = 0;

        while(counter <= times.length){
            nowhp = nowhp + noweffects;

            if(nowhp < 0){
                nowhp = 0;
            }

            if(nowhp > maxhp){
                nowhp = maxhp;
            }

            if(nowhp == 0 || nowhp == maxhp){
                answer++;
            }

            if(curtime == times[counter]){
                noweffects = noweffects + effects[counter];
                counter++;
            }
            curtime++;
        }

        return answer;
    }
}