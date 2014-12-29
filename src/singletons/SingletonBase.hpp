//#ifndef __SINGLETON_HPP_
//#define __SINGLETON_HPP_
//
//#include <memory>
//#include <mutex>
//#include <iostream>
//#include "../utils/test-tools.hpp"
//
//template<class SingletonClass>
//class Singleton : public SingletonClass
//{
//public:
//    /** Singleton creation function */
//    static Singleton & Instance()
//    {
//        if(m_instance.get() == NULL)
//        {
//            m_instance = std::unique_ptr<Singleton<SingletonClass> >(new Singleton);
//            ASSERT(m_instance.get() != NULL, "Trying to make second intance of singleton class");
//        }
//        return *m_instance;
//    }
//
//
//protected:
//    /** Singleton instance holder */
//    static std::unique_ptr<Singleton<SingletonClass> > m_instance;
//};
//
///** static instance definition */
//template<class SingletonClass> std::unique_ptr<Singleton<SingletonClass> > Singleton<SingletonClass>::m_instance;
//
//
//#endif
