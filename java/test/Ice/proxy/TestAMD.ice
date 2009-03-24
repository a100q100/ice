// **********************************************************************
//
// Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef TEST_AMD_ICE
#define TEST_AMD_ICE

#include<Ice/Current.ice>

[["java:package:test.Ice.proxy.AMD"]]
module Test
{

["ami", "amd"] class MyClass
{
    void shutdown();

    Ice::Context getContext();
};

["ami", "amd"] class MyDerivedClass extends MyClass
{
    Object* echo(Object* obj);
};

};

#endif
