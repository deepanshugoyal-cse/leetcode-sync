class Solution {
public:
    int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int convert(string s){
        int m=stoi(s.substr(0,2));
        int d=stoi(s.substr(3,2));

        for(int i=0; i<m-1; i++){
            d+=days[i];
        }
        return d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa=convert(arriveAlice);
        int la=convert(leaveAlice);
        int ab=convert(arriveBob);
        int lb=convert(leaveBob);

        int st=max(aa,ab);
        int end=min(lb,la);

        return max(0,end-st+1);
    }
};