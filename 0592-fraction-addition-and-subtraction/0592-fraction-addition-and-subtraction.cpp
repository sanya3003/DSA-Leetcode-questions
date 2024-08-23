class Solution {
public:
    string fractionAddition(string expr) {
        int nume=0;
        int deno=1;

        int i=0;
        int n= expr.size();
        while(i<n){
            int currNume=0;
            int currDeno=0;

            bool isNeg = (expr[i] == '-');

            if(expr[i] == '+' || expr[i] == '-'){
                i++;
            }
            // build the currNume
            while(i<n && isdigit(expr[i])){
                int val = expr[i]-'0';
                currNume = (currNume*10) + val;
                i++;

            }
            i++; // skiping the divisor character/"

            if(isNeg == true){
                currNume *= -1;
            }

            // build the current denominator
            while(i<n && isdigit(expr[i])){
                int val = expr[i]-'0';
                currDeno = (currDeno*10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;

        }
        //num
        // deno
        int GCD = abs(__gcd(nume, deno));
        nume /= GCD;
        deno /= GCD;
        return to_string(nume) + "/" + to_string(deno);
    }
};