#ifndef __SINGLETON_HPP_
#define __SINGLETON_HPP_

#include <memory>
#include <mutex>
#include <iostream>
#include "../utils/test-tools.hpp"

//template <class T>
//class Singleton
//{
//public:
//    static T& Instance() {
//        std::call_once(m_once_flag, [] {
//            m_instance.reset(new T);
//        });
//        return *m_instance.get();
//    }
////    static T* Instance() {
////        if(!m_pInstance) m_pInstance = new T;
////        assert(m_pInstance != NULL);
////        return m_pInstance;
////    }
//protected:
//    Singleton();
//    ~Singleton();
//private:
//    Singleton(Singleton const&);
//    Singleton& operator=(Singleton const&);
//    static T* m_pInstance;
//    static std::unique_ptr<T> m_instance;
//    static std::once_flag m_once_flag;
//};
//
//template <class T> T* Singleton<T>::m_pInstance=NULL;


template<class SingletonClass>
class Singleton : public SingletonClass
{
public:
    /** Singleton creation function */
    static Singleton & Instance()
    {
        if(m_instance.get() == NULL)
        {
            m_instance = std::unique_ptr<Singleton<SingletonClass> >(new Singleton);
            ASSERT(m_instance.get() != NULL, "Trying to make second intance of singleton class");
        }
        return *m_instance;
    }


protected:
    /** Singleton instance holder */
    static std::unique_ptr<Singleton<SingletonClass> > m_instance;
};

/** static instance definition */
template<class SingletonClass> std::unique_ptr<Singleton<SingletonClass> > Singleton<SingletonClass>::m_instance;


#endif
