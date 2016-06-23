#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

static unsigned digits[20];


size_t reverse(size_t num);

template<class T>
T expo(T a, T b);

template<int> size_t findNumDigits(size_t x); 
template<> size_t findNumDigits<4>(size_t x){
	x = abs(x);  
    return (x < 10 ? 1 :   
    	(x < 100 ? 2 :   
    	(x < 1000 ? 3 :   
    	(x < 10000 ? 4 :   
    	(x < 100000 ? 5 :   
    	(x < 1000000 ? 6 :   
    	(x < 10000000 ? 7 :  
    	(x < 100000000 ? 8 :  
    	(x < 1000000000 ? 9 :	
    	10)))))))));  

}
template<> size_t findNumDigits<8>(size_t x){
    return (x < static_cast<size_t>(10)? 1 :   
    	(x < static_cast<size_t>(100)? 2 :   
    	(x < static_cast<size_t>(1000)? 3 :   
    	(x < static_cast<size_t>(10000)? 4 :   
    	(x < static_cast<size_t>(100000)? 5 :   
    	(x < static_cast<size_t>(1000000)? 6 :   
    	(x < static_cast<size_t>(10000000)? 7 :  
    	(x < static_cast<size_t>(100000000)? 8 :  
    	(x < static_cast<size_t>(1000000000)? 9 :	
	(x < static_cast<size_t>(10000000000)? 10 :
	(x < static_cast<size_t>(100000000000)? 11 :
	(x < static_cast<size_t>(1000000000000)? 12 :
	(x < static_cast<size_t>(10000000000000)? 13 :
	(x < static_cast<size_t>(100000000000000)? 14 :
	(x < static_cast<size_t>(1000000000000000)? 15 :
	(x < static_cast<size_t>(10000000000000000)? 16 :
	(x < static_cast<size_t>(100000000000000000)? 17 :
	(x < static_cast<size_t>(1000000000000000000)? 18 :
	(x < static_cast<size_t>(10000000000000000000)? 19:  
    	20)))))))))))))))))));  

}

size_t allRevs(size_t num);
bool isAllOdds(size_t num);

int main(int argc, char*argv[]){
	if(argc!=2){
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	//else
	//char* temp;
	//size_t numVersion = std::strtoull(argv[1], &temp, 10);
	//std::cout<<numVersion<<std::endl;
	//std::cout<<reverse(numVersion)<<std::endl;
	
	size_t test = 999;//expo(static_cast<size_t>(10),static_cast<size_t>(18));
	std::cout<<allRevs(test)<<std::endl;
	return 0;
}

size_t allRevs(size_t num){
	if(num<=11)
		return 0;
	//else
	size_t retVal(0);
	for(size_t i = 11; i<=num; i++){
		if(!i%10) //check trailing zeros
			continue;		
		if(isAllOdds(i+reverse(i)))
			retVal++;
	}
	return retVal;
}

bool isAllOdds(size_t num){
	size_t numDigits(findNumDigits<sizeof(size_t)>(num));
	size_t o = num;
	for(size_t i = expo(static_cast<size_t>(10),numDigits-1), ix=numDigits; i>=1; i/=10,ix--){
		digits[ix-1] = num/i;
		num%=i;
	}
	for(size_t i = 0; i<numDigits; i++)
		if(digits[i]%2==0){
			return false;
		}
	std::cout<<o;
	std::cout<<'\t'<<true<<std::endl;
	return true;
}

template<class T>
T expo(T a, T b){
    T result(1);
    while(b) {
        if(b & 1)result *= a;
        b >>=1 ;
        a *= a;
    }
    return result;
}


size_t reverse(size_t num){
	size_t numDigits(findNumDigits<sizeof(size_t)>(num));
	size_t retVal(0);
	for(size_t i = expo(static_cast<size_t>(10),numDigits-1), ix=numDigits; i>=1; i/=10,ix--){
		digits[ix-1] = num/i;
		num%=i;
	}	
	for(size_t i = numDigits, ix = 0; i>0; i--,ix++){
		retVal+=digits[i-1]*expo(static_cast<size_t>(10),ix);
	}
	return retVal;
}
