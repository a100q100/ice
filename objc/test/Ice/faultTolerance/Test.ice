// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice Touch is licensed to you under the terms described in the
// ICE_TOUCH_LICENSE file included in this distribution.
//
// **********************************************************************

#pragma once

module Test
{

interface TestIntf
{
    void shutdown();
    void abort();
    idempotent void idempotentAbort();
    idempotent int pid();
};

};
