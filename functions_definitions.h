#include "class.h"


bool bigInt::is_bigInt(string s){
    if(s[0]=='-')
        s.erase(0,1);
    for(unsigned long long int i=0;i<s.length();++i){
        if(!((int)s[i]>47 && (int)s[i]<58))
            return false;
    }    
    return true;
}
//function definition for Addition
string bigInt::add(string str1,string str2){
    int str1_len=str1.length();
    int str2_len=str2.length();

    string sum="";

    if (str1_len==0 && str2_len==0){
        sum = "0";
    }
    else if(str1[0] == '-' && str2[0]== '-'){
        if(str1_len==1 && str2_len==1){
        sum = "0";
        }
        else{
            sum = "-" + add(str1.erase(0,1),str2.erase(0,1));
        }   
    }
    else if(str1[0]=='-'){
        sum = subtract(str2,str1.erase(0,1));
    }
    else if(str2[0]=='-'){
        sum = subtract(str1,str2.erase(0,1));
    }
    else{
        int i,j,track_sum,carry=0;
        for(i=str1_len-1, j = str2_len-1;i>=0 && j>=0;--i,--j ){
            track_sum = ((int)str1[i])-48 + ((int)str2[j])-48 + carry;
            carry = track_sum/10;
            sum = to_string(track_sum%10) + sum;
        }
        if(i>=0 && j<0){
            for(; i>=0 ;--i){
                track_sum=((int)str1[i])-48 + carry;
                carry = track_sum/10;
                sum = to_string(track_sum%10)+sum;
            }
        }
        else if(j>=0 && i<0){
            for(;j>=0;--j){
                track_sum=((int)str2[j])-48 + carry;
                carry = track_sum/10;
                sum = to_string(track_sum%10)+sum;
            }
        }
        if(carry){
            sum =to_string(carry)+sum;
        }
    }
    return trim(sum);
}

//function definition for subtraction
string bigInt::subtract(string str1,string str2){
    int str1_len=str1.length();
    int str2_len=str2.length();

    string sum="";
    if(str1==str2){
        //if length equal
        return "0";
    }
    else if(str1[0]=='-' && str2[0]=='-'){
        // if both negative
        if(str1_len==1 && str2_len==1){
            // if 
            sum="0";
        }
        else{
            bigInt t1(str1.erase(0,1));
            bigInt t2(str2.erase(0,1));
            string temp= subtract(t2.str , t1.str);
            bigInt mx= maximum(t2.str,t1.str);
            if(temp[0]!='-' && mx.str == t1.str)
                sum="-"+temp;
            else
                sum=temp;   
        }
    }
    else if(str1[0]=='-'){
        sum = "-" + add(str1.erase(0,1),str2);
    }
    else if(str2[0]=='-'){
        sum = add(str1,str2.erase(0,1));
    }
    else{
        //implement the logic for subtraction
        int i,j,track_sum,carry=0;
        if(str1_len<str2_len){
            string tp=str1;
            str1=str2;
            str2=tp;
            sum ="-"+subtract(str1,str2);
            return trim(sum);
        }
        else if(str1_len==str2_len){
            bigInt a(str1);
            bigInt b(str2);
            bigInt mx= maximum(a.str,b.str);
            if(mx.str == str2){
                string tp =str1;
                str1= str2;
                str2 = tp;
                bigInt t1(str1);
                bigInt t2(str2);
                bigInt temp= subtract(str1,str2);
                sum ="-"+ subtract(str1,str2);
                return trim(sum);
            }
        }
        int val1,val2;
        for(i=str1_len-1 ,j=str2_len-1;i>=0 || j>=0;--i,--j){
            if(i>=0){
                val1=str1[i]-'0';
            }
            else{
                val1=0;
            }
            if(j>=0){
                val2 = str2[j]-'0';
            }
            else{
                val2=0;
            }
            track_sum = val1 -val2 - carry;
            if(track_sum<0){
                track_sum += 10;
                carry =1;
            }
            else {
                carry =0;
            }
            sum = to_string(track_sum) + sum;
        }
    }
    return trim(sum);
}

//function definition for multplication
string bigInt::multiply(string str1,string str2){
    bool toAddNeg= false;
    int str1_len=str1.length();
    int str2_len=str2.length();
    string ans="";
    if(str1[0]=='-' && str2[0]=='-'){
        //if both is negative
        ans =multiply(str1.erase(0,1),str2.erase(0,1));
    }
    else if(str1[0]=='-'){
        //if string 1 is negative
        toAddNeg=true;
        ans = multiply(str1.erase(0,1),str2);
    }
    else if(str2[0]=='-'){
        //if string 2 is negative
        toAddNeg=true;
        ans = multiply(str1,str2.erase(0,1));
    }
    else{
        //logic for multplication
        if(str1_len==0 || str2_len==0){
            return "0";
        }
        vector<int> result(str1_len+str2_len,0);
        int i_n1=0;
        int i_n2=0;
        for(int i=str1_len-1;i>=0;i--){
            int carry=0;
            int n1=str1[i]-'0';
            i_n2=0;
            for(int j=str2_len-1;j>=0;j--){
                int n2=str2[j]-'0';
                int sum=n1*n2+result[i_n1+i_n2]+carry;
                carry=sum/10;
                result[i_n1+i_n2]=sum %10;
                i_n2++;
            }
            if(carry>0)
                result[i_n1+i_n2]+=carry;
            i_n1++;    
        }
        int i=result.size()-1;
        while(i>=0 && result[i]==0)
            i--;
         if(i== -1)
            return "0";
        while(i>=0)
            ans += to_string(result[i--]);       
    }
    if(toAddNeg && ans[0]!='0'){
        ans ='-' + ans;
    }
    return ans;
}

//functions for division 
string bigInt::divide(string str1,string str2){
    string ans="";
    if(str2=="0"){
        return "0";
    }
    else if(str1==str2){
        return "1";
    }
    else if(str1[0]=='-' && str2[0]=='-'){
        ans= divide(str1.erase(0,1) , str2.erase(0,1));
    }
    else if(str1[0]=='-'){
        string temp = divide(str1.erase(0,1),str2);
        if(temp =="0")
            ans = temp;
        else 
            ans = '-' + temp;    
    }
    else if(str2[0]=='-'){
        string temp =divide(str1,str2.erase(0,1));
        if(temp =="0")
            ans = temp;
        else
            ans = '-' + temp;   
    }
    else{
        if(str2=="1")
            return str1;
        if(is_strictlyMaximum(str2,str1)){
            return "0";
        } 
        if(str2.length()<=19){
            stringstream strstrm(str2);
            unsigned long long int int_str2 = 0;
            strstrm >> int_str2;
            ans = shortDivide(str1,int_str2);
        } 
        else{
            string temp=str2;
            ans ="0";
            string count=0;
            while(str1==maximum(str1,str2)){
                int lenDiff=str1.length()-str2.length();
                if(lenDiff>0 && str1[0]>str2[0]){
                    count= add(count,pow("10",to_string(lenDiff)));
                    str1=subtract(str1,multiply(str2,pow("10",to_string(lenDiff))));
                }
                else if(lenDiff>0){
                    count=add(count,pow("10",to_string(lenDiff-1)));
                    str1=subtract(str1,multiply(str2,pow("10",to_string(lenDiff-1))));
                }
                else{
                    count=add(count,"1");
                    str1=subtract(str1,str2);
                }
            }
            ans = count;
        }  
    }
    return ans;
}

//short Divide
string bigInt::shortDivide(string s1,unsigned long long int divisor){
    string ans;
    int idx=0;
    long long int temp=s1[idx]-'0';
    while(temp<divisor){
        temp=temp*10+(s1[++idx]-'0');
        if(idx>=s1.length())
            break;
    }
    while(s1.length()>idx){
        ans += (temp/divisor)+'0';
        temp=(temp%divisor)*10+s1[++idx]-'0';
    }
    if(ans.length()==0)
        return "0";
    return ans;    
}
string bigInt::mod(string str1,string str2){
    string ans=subtract(str1,multiply(divide(str1,str2),str2));
    return ans;
}
//maximum function
string bigInt::maximum(string str1,string str2){
    string max="";
    bool bothNeg=false;
    bool isMax1=false;
    bool isMax2=false;
    if(str1[0]=='-' && str2[0]=='-'){
        bothNeg=true;
        str1.erase(0,1);
        str2.erase(0,1);
    }
    else if(str1[0]=='-'){
        return trim(str2);
    }
    else if(str2[0]=='-'){
        return trim(str1);
    }
    int str1_len=str1.length(),str2_len=str2.length();
    if(str1_len==str2_len){
        for(int i=0;i<str1_len;++i){
            if(str1[i]!=str2[i]){
                if(str1[i]>str2[i]){
                    isMax1=true;
                }
                else{
                    isMax2=true;
                }
                break;
            }
        }
        if(!(isMax2 ^ isMax1)){
            isMax1=true;
        }
    }
    else if(str1_len>str2_len){
        isMax1=true;
    }
    else{
        isMax2=true;
    }
    if(bothNeg){
        if(isMax1)
            return ("-" + trim(str2));
        else
            return ("-" + trim(str1));    
    }
    else{
        if(isMax1)
            return trim(str1);
        else
            return trim(str2);    
    }
}
string bigInt::minimum(string str1,string str2){
    string ans=maximum(str1,str2);
    if(ans==str1)
        return str1;
    return str2;
} 

bool bigInt::is_maximum(string str1,string str2){
    if(str1==maximum(str1,str2))
        return true;
    return false;    
}

bool bigInt::is_minimum(string str1,string str2){
    if(str2==maximum(str1,str2))
        return true;
    return false;    
}

bool bigInt::is_strictlyMaximum(string str1,string str2){
    if(str1==str2)
         return false;
    if(str1==maximum(str1,str2))
        return true;
    return false;        
}

bool bigInt::is_strictlyMinimum(string str1,string str2){
    if(str1==str2)
         return false;
    if(str2==maximum(str1,str2))
        return true;

    return false;       
}

string bigInt::trim(string s){
    if(s=="0")
        return s;
    if(s[0]=='-'){
        int i=1;
        while(s[i] =='0'){
            s.erase(i,1);
        }
        return s;
    }    
    else if(s[0]=='0'){
        int i=0;
        while(s[i]=='0'){
            s.erase(i,1);
        }
        return s;
    }
    return s;;
}

string bigInt::pow(string str1,string str2){
    if(str2=="0"){
        return "1";
    }
    else if(str1=="0"){
        if(str2[0]=='-'){
            return to_string((long long int) std::pow(0,-5));
        }
        return "0";
    }
    else if(str1[0]=='-' && str2[0]=='-'){
        if(str1=="-1" && str2=="-1"){
            return "-1";
        }
        else if(str1=="-1"){
            if((((int)str2[str2.length()-1])-48) & 1){
                return "-1";
            }
            else {
                return "1";
            }
        }
        else{
            return "0";
        }
    }
    else if(str1[0]=='-'){
        if((((int)str2[str2.length()-1])-48) & 1)
            return '-' + pow(str1.erase(0,1),str2);
        return  pow(str1.erase(0,1),str2);   
    }
    else if(str2[0]=='-'){
        if(str1=="1"){
            return str1;
        }
        else{
            return "0";
        }
    }
    else{
        string init_str1=str1;
        while(str2!="1"){
            str1= multiply(str1,init_str1);
            str2=subtract(str2,"1");
        }
        return str1;
    }
}
string bigInt::abs(string s){
    if(s[0]=='-')
        s.erase(0,1);
    return s;    
}
string bigInt::sqrt(string s){
    if(s[0]=='-')
        return s;
    if(s=="0")
        return "0";
    unsigned long long int s_len=s.length();
    string ans;
    string mid="";
    string high,low,square;
    unsigned long long int ans_len=s_len>>1;
    if(s_len & 1){
        string toPut="10";
        low = pow(toPut,to_string(ans_len));
        high = pow(toPut,to_string(ans_len + 1));
    } 
    else{
        low=pow("10",to_string(ans_len-1));
        high=pow("10",to_string(ans_len));
    }       
    string prev;
    while(1){
        mid=divide(add(high,low),"2");
        square = multiply(mid,mid);
        if(prev == mid || (maximum(add(square,mid),s)==add(square,mid) && maximum(square,s)==s) || high==low){
            break;
        }
        if(maximum(square,s)==s){
            low= mid;
        }
        else if(maximum(square,s)==square){
            high=mid;
        }
        prev=mid;
    }
    ans=mid;
    return ans;
}
string bigInt::fact(string s){
    if(s[0]=='-'){
        throw runtime_error("Factorial of negative Integer is not defined");
    }
    if(s=="0")
        return "1";
    string ans ="1";
    while(s!="0"){
        ans=multiply(ans,s);
        s=subtract(s,"1");
    }    
    return ans;
}
bool bigInt::isPalindrome(string s){
    if(s[0]=='-')
        s.erase(0,1);
    unsigned long long int beg=0,end=s.length()-1;
    while(beg<end){
        if(s[beg]!=s[end])
            return false;
        beg++;
        end--;    
    }    
    return true;
}

bool bigInt::isPrime(string s) {           
    if(maximum(s, "2") != s)
        return false;
    string sqrt = bigInt::sqrt(s);
    string i = "";
    for(i = "2"; is_maximum(sqrt, i); i = add(i, "1")) {
        if(mod(s, i) == "0")
            return false;
    }
    return true;
}