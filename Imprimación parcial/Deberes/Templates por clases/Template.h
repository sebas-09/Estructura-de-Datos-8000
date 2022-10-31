#include <iostream>
#include <stdlib.h>





template <typename T>
class Numero{
	public: 
		void setNum(T n);
		T getNum() const;
	private:
		T num;	
};
template <typename T>
void Numero<T>::setNum(T n){
		this->num=n;
}
template <typename T>
T Numero<T>::getNum()const{
		return this->num;
}