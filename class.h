#include<string>
#include<vector>
#include<math.h>
#include <sstream>
#include<limits>
#include<iostream>

using namespace std;

class bigInt{
    private:
    //only data member for big Integer
    string str;

    //functions Definitions for Internal Uses

    static string trim(string);
    static string add(string, string);
    static string subtract(string, string);
    static string multiply(string, string);
    static string divide(string, string);
    static string mod(string, string);
    //----------------------------------------------------//
    static bool is_bigInt(string);
    static string pow(string, string);
    static string shortDivide(string,unsigned long long int);
    static string maximum(string,string);
    static string minimum(string,string);
    static bool is_maximum(string , string);
    static bool is_minimum(string , string);
    static bool is_strictlyMaximum(string,string);
    static bool is_strictlyMinimum(string,string);
    //----------------------------------------------------//
    static bool isPalindrome(std::string);
    static bool isPrime(std::string);
    static string fact(string s);
    static string abs(string);
    static string sqrt(string);
    public:

    //constructors for big Int.
    bigInt(){
        str='0'; //default value
    }
    bigInt(string s){
        if(!is_bigInt(s))
          throw runtime_error("invalid big Integer has been fed");
        str = s;  
    }
    bigInt(long long int n){
        str= to_string(n);
    }
    bigInt(int n){
        str= to_string(n);
    }
    bigInt(long int n){
        str= to_string(n);
    }
    bigInt(const bigInt &n) {
            this->str = n.str;
    }
    //operator overloading for output stream {<<}
    friend ostream & operator << (ostream &out, const bigInt &n){
        out<<n.str;
        return out;
    }
    //operator overloading for input stream {>>}
    friend istream & operator >> (istream &in, bigInt &n){
        in >> n.str;
        return in;
    }

    /* Operator {+}Overloadings for different kind of parameter 
    for the programmer's convinience 
    */

   bigInt operator + (bigInt const &n){
        bigInt ans;
        ans.str =add(this->str,n.str);
        return ans;
   }
    bigInt operator + (int n2){
        bigInt ans;
        ans.str =add(this->str,to_string(n2));
        return ans;
   }
   friend bigInt operator + (int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = add(n2.str, to_string(n1));
            return ans;
    }
    friend bigInt operator + (long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = add(n2.str, std::to_string(n1));
            return ans;
    }
    friend bigInt operator + (bigInt const &n1,long int n2){
         bigInt ans;
            ans.str = add(to_string(n2),n1.str);
            return ans;
    }
    friend bigInt operator + (long long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = add(n2.str, std::to_string(n1));
            return ans;
    }
    friend bigInt operator + (bigInt const &n1,long long int n2){
         bigInt ans;
            ans.str = add(to_string(n2),n1.str);
            return ans;
    }

    //extra shortcut feature
    bigInt& operator += (bigInt const n){
        (*this).str = add((*this).str , n.str);
        return  (*this);
    }


    /* Operator{-} Overloadings for different kind of parameter 
    for the programmer's convinience 
    */

   bigInt operator - (bigInt const &n){
        bigInt ans;
        ans.str =subtract(this->str,n.str);
        return ans;
   }
    bigInt operator - (int n2){
        bigInt ans;
        ans.str =subtract(str,to_string(n2));
        return ans;
   }
//    bigInt operator - (int n1) {
//             bigInt ans;
//             ans.str = subtract(to_string(n1),str);
//             return ans;
//     }
     bigInt operator - (long int n1) {
            bigInt ans;
            ans.str = subtract(to_string(n1),str);
            return ans;
    }
    //  bigInt operator - (long int n2){
    //      bigInt ans;
    //         ans.str = subtract(str,to_string(n2));
    //         return ans;
    // }
     bigInt operator - (long long int n1) {
            bigInt ans;
            ans.str = subtract(to_string(n1),str);
            return ans;
    }
    //  bigInt operator - (long long int n2){
    //      bigInt ans;
    //         ans.str = subtract(str,to_string(n2));
    //         return ans;
    // }

    //extra shortcut feature
    bigInt& operator -= (bigInt const n){
        (*this).str = subtract((*this).str , n.str);
        return  (*this);
    }
    

    /* Operator{*} Overloadings for different kind of parameter 
    for the programmer's convinience 
    */

   bigInt operator * (bigInt const &n){
        bigInt ans;
        ans.str =multiply(this->str,n.str);
        return ans;
   }
    friend bigInt operator * (bigInt const &n1,int n2){
        bigInt ans;
        ans.str =multiply(n1.str,to_string(n2));
        return ans;
   }
   friend bigInt operator * (int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = multiply(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator * (long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = multiply(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator * (bigInt const &n1,long int n2){
         bigInt ans;
            ans.str = multiply(n1.str,to_string(n2));
            return ans;
    }
    friend bigInt operator * (long long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = multiply(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator * (bigInt const &n1,long long int n2){
         bigInt ans;
            ans.str = multiply(n1.str,to_string(n2));
            return ans;
    }

    //extra shortcut feature
    bigInt& operator *= (bigInt const n){
        (*this).str = multiply((*this).str , n.str);
        return  (*this);
    }

    
    /* Operator{/} Overloadings for different kind of parameter 
    for the programmer's convinience 
    */

   bigInt operator / (bigInt const &n){
        bigInt ans;
        ans.str =divide(this->str,n.str);
        return ans;
   }
    friend bigInt operator / (bigInt const &n1,int n2){
        bigInt ans;
        ans.str =divide(n1.str,to_string(n2));
        return ans;
   }
   friend bigInt operator / (int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = divide(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator / (long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = divide(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator / (bigInt const &n1,long int n2){
         bigInt ans;
            ans.str = divide(n1.str,to_string(n2));
            return ans;
    }
    friend bigInt operator / (long long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = divide(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator / (bigInt const &n1,long long int n2){
         bigInt ans;
            ans.str = divide(n1.str,to_string(n2));
            return ans;
    }

    //extra shortcut feature
    bigInt& operator /= (bigInt const n){
        (*this).str = divide((*this).str , n.str);
        return  (*this);
    }

     /* Operator{%} Overloadings for different kind of parameter 
    for the programmer's convinience 
    */

   bigInt operator % (bigInt const &n){
        bigInt ans;
        ans.str = mod(this->str,n.str);
        return ans;
   }
    friend bigInt operator % (bigInt const &n1,int n2){
        bigInt ans;
        ans.str =mod(n1.str,to_string(n2));
        return ans;
   }
   friend bigInt operator % (int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = mod(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator % (long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = mod(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator % (bigInt const &n1,long int n2){
         bigInt ans;
            ans.str = mod(n1.str,to_string(n2));
            return ans;
    }
    friend bigInt operator % (long long int n1, bigInt const &n2) {
            bigInt ans;
            ans.str = mod(to_string(n1),n2.str);
            return ans;
    }
    friend bigInt operator % (bigInt const &n1,long long int n2){
         bigInt ans;
            ans.str = mod(n1.str,to_string(n2));
            return ans;
    }

    //extra shortcut feature
    bigInt& operator %= (bigInt const n){
        (*this).str = mod((*this).str , n.str);
        return  (*this);
    }

    //------------------------------------------------
    //-----------INCREMENTER AND DECREMENETER--------
    //-----------------------------------------------

     /* Operator {++} Overloadings
        for the pre incremention  */
    bigInt& operator++ (){
        (*this).str=add((*this).str,"1");
        return (*this);
    }
    /* Operator {++} Overloadings
        for the post incremention  */
    bigInt operator ++ (int) {
        (*this).str = add((*this).str, "1"); 
         return (*this);
    }
     /* Operator {--} Overloadings
        for the pre decremention  */
    bigInt& operator -- () {
        (*this).str = subtract((*this).str, "1");
        return (*this);
    }
     /* Operator {--} Overloadings
        for the post incremention  */
    bigInt operator -- (int) {
        (*this).str = subtract((*this).str, "1"); 
            return (*this);
    }

     //-------------------------------------------------
     //---------Conditional Operators------------------
     //-----------------------------------------------


     /* Operator {>} Overloadings */
     bool operator > (bigInt const &n){
        return is_strictlyMaximum(str,n.str);
     }
       bool operator > (int n2){
        return is_strictlyMaximum(str,to_string(n2));
     }
    //  bool operator > (int n1){
    //     return is_strictlyMaximum(to_string(n1),this->str);
    //  }
     bool operator > (long int n2){
        return is_strictlyMaximum(this->str,to_string(n2));
     }
    //  bool operator > (long int n1){
    //     return is_strictlyMaximum(to_string(n1),this->str);
    //  }
     bool operator > (long long int n2){
        return is_strictlyMaximum(this->str,to_string(n2));
     }
    //  bool operator > (long long int n1){
    //     return is_strictlyMaximum(to_string(n1),this->str);
    //  }



     /* Operator {<} Overloadings */
     bool operator < (bigInt const &n){
        return is_strictlyMinimum(str,n.str);
     }
     bool operator < (int n2){
        return is_strictlyMinimum(this->str,to_string(n2));
     }
    //  bool operator < (int n1){
    //     return is_strictlyMinimum(to_string(n1),this->str);
    //  }
     bool operator < (long int n2){
        return is_strictlyMinimum(this->str,to_string(n2));
     }
    //  bool operator < (long int n1){
    //     return is_strictlyMinimum(to_string(n1),this->str);
    //  }
     bool operator < (long long int n2){
        return is_strictlyMinimum(this->str,to_string(n2));
     }
    //  bool operator < (long long int n1){
    //     return is_strictlyMinimum(to_string(n1),this->str);
    //  }


     /* Operator {>=} Overloadings */
     bool operator >= (bigInt const &n){
        return is_maximum(str,n.str);
     }
     bool operator >= (int n2){
        return is_maximum(this->str,to_string(n2));
     }
    //  bool operator >= (int n1){
    //     return is_maximum(to_string(n1),this->str);
    //  }
     bool operator >= (long int n2){
        return is_maximum(this->str,to_string(n2));
     }
    //  bool operator >= (long int n1){
    //     return is_maximum(to_string(n1),this->str);
    //  }
     bool operator >= (long long int n2){
        return is_maximum(this->str,to_string(n2));
     }
    //  bool operator >= (long long int n1){
    //     return is_maximum(to_string(n1),this->str);
    //  }


    /* Operator {<=} Overloadings */
     bool operator <= (bigInt const &n){
        return is_minimum(str,n.str);
     }
     bool operator <= (int n2){
        return is_minimum(this->str,to_string(n2));
     }
    //  bool operator <= (int n1){
    //     return is_minimum(to_string(n1),this->str);
    //  }
     bool operator <= (long int n2){
        return is_minimum(this->str,to_string(n2));
     }
    //  bool operator <= (long int n1){
    //     return is_minimum(to_string(n1),this->str);
    //  }
     bool operator <= (long long int n2){
        return is_minimum(this->str,to_string(n2));
     }
    //  bool operator <= (long long int n1){
    //     return is_minimum(to_string(n1),this->str);
    //  }

     /*Operator {==} overloading */
     bool operator == (bigInt const &n){
        return (*this).str==n.str;
     }
     bool operator == (int n2){
        return (*this).str==to_string(n2);
     }
    //  bool operator == (int n1){
    //     return (*this).str==to_string(n1);
    //  }
     bool operator == (long int n2){
        return (*this).str==to_string(n2);
     }
    //  bool operator == (long int n1){
    //    return (*this).str==to_string(n1);
    //  }
     bool operator == (long long int n2){
        return (*this).str==to_string(n2);
     }
    //  bool operator == (long long int n1){
    //     return (*this).str==to_string(n1);
    //  }


     /*Operator {!=} overloading */
     bool operator != (bigInt const &n){
        return (*this).str!=n.str;
     }
    //  bool operator != (int n2){
    //     return (*this).str!=to_string(n2);
    //  }
     bool operator != (int n1){
        return (*this).str!=to_string(n1);
     }
    //  bool operator != (long int n2){
    //     return (*this).str!=to_string(n2);
    //  }
     bool operator != (long int n1){
       return (*this).str!=to_string(n1);
     }
    //  bool operator != (long long int n2){
    //     return (*this).str!=to_string(n2);
    //  }
     bool operator != (long long int n1){
        return (*this).str!=to_string(n1);
     }
     //--------------------------------------------------
     //-------Function Definition for External USe-------
     //--------------------------------------------------

    //for use
     static bigInt big_fact(bigInt &a) {                
            bigInt ans;
            ans.str = fact(a.str);
            return ans;
    }
    static bool _big_isPalindrome(bigInt &a) {              
            return isPalindrome(a.str);
    }
    static bool _big_isPrime(bigInt &a) {     
            return isPrime(a.str);
    }    
     //to big integer functions
     static bigInt to_bigInt(string s){
        bigInt ans;
        ans.str=s;
        return ans;
     }
     static bigInt to_bigInt(int n){
        bigInt ans;
        ans.str=to_string(n);
        return ans;
     }
     static bigInt to_bigInt(long int n){
        bigInt ans;
        ans.str=to_string(n);
        return ans;
     }
     static bigInt to_bigInt(long long int n){
        bigInt ans;
        ans.str=to_string(n);
        return ans;
     }
} ;