// **********************************************************************
//
// Copyright (c) 2001
// Mutable Realms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef ICE_UTIL_THREAD_H
#define ICE_UTIL_THREAD_H

#include <IceUtil/Shared.h>
#include <IceUtil/Handle.h>

namespace IceUtil
{

class Time;

#ifdef _WIN32
struct HandleWrapper : public Shared
{
    // Inline for performance reasons.
    HandleWrapper(HANDLE h) :
	handle(h)
    {
    }

    // Inline for performance reasons.
    virtual ~HandleWrapper()
    {
	if(handle)
	{
	    CloseHandle(handle);
	}
    }

    HANDLE handle;
};

typedef Handle<HandleWrapper> HandleWrapperPtr;
#endif

class ICE_UTIL_API ThreadControl
{
public:

    ThreadControl();

#ifdef _WIN32
    ThreadControl(const HandleWrapperPtr&, unsigned);
#else
    ThreadControl(pthread_t);
#endif

    bool operator==(const ThreadControl&) const;
    bool operator!=(const ThreadControl&) const;
    bool operator<(const ThreadControl&) const;

    //
    // Wait until the controlled thread terminates. The call has POSIX
    // semantics.
    //
    // At most one thread can wait for the termination of a given
    // thread.C alling join on a thread on which another thread is
    // already waiting for termination results in undefined behaviour.
    //
    void join();

    static void sleep(const Time&);
    static void yield();

private:

#ifdef _WIN32
    HandleWrapperPtr _handle;
    unsigned _id;
#else
    pthread_t _id;
#endif
};

class ICE_UTIL_API Thread : virtual public IceUtil::Shared
{
public:

    Thread();
    virtual ~Thread();

    virtual void run() = 0;

    ThreadControl start();

    ThreadControl getThreadControl();

    bool operator==(const Thread&) const;
    bool operator!=(const Thread&) const;
    bool operator<(const Thread&) const;

private:

#ifdef _WIN32
    unsigned _id;
    HandleWrapperPtr _handle;
#else
    pthread_t _id;
#endif
};

typedef Handle<Thread> ThreadPtr;
    
}

#endif

