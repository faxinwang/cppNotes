/*
	class auto_ptr
	improved standard confomring implementation
*/

namespace mylib{
	template<class Y>
	//auxiliary type to enable copies and assignments(now global)
	struct auto_ptr_ref{
		Y* yp;
		auto_ptr_ref(Y* rhs):yp(rhs){}
	};
	
	template<class T>
	class auto_ptr{
		private:
			T *ap;//refer to the actual owned object
		public:
			typedef T element_type;
			
			//constructor
			explicit auto_ptr(T* ptr=0)throw():ap(ptr){};
			//copy constructor
			auto_ptr(auto_ptr& rhs)throw():ap(rhs.release()){}
			template<class Y>
			auto_ptr (auto_ptr<Y>& rhs) throw():ap(rhs.release()){}
			
			auto_ptr& operator=(auto_ptr& rhs)throw(){
				reset(rhs.release());
				return *this;
			}
			~auto_ptr()throw(){
				delete ap;
			}
			T* get()const throw(){
				return ap;
			}
			T& operator*()const throw(){
				return *ap;
			}
			T* operator->()const throw(){
				return ap;
			}
			T* release()throw(){
				T* tmp(ap);
				ap=0;
				return tmp;
			}
			void reset(T* ptr=0)throw(){
				if(ap!=ptr){
					delete ap;
					ap=ptr;
				}
			}
			
			auto_ptr& operator=(auto_ptr_ref<T> rhs)throw(){
				reset(rhs.yp);
				return *this;
			}
	};
}

