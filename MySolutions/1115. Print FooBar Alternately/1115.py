# ============================================================================
# Name        : Leetcode.1115. Print FooBar Alternately
# Author      : sanstwy27
# Version     : Version 1.0.0
# Copyright   :
# Description : Any %
# Reference   : https://leetcode.com/problems/print-foobar-alternately/discuss/336629/
#               5-Python-threading-solutions-(Barrier-Event-Condition-Lock-Semaphore)-
#               with-explanation
#               https://stackoverflow.com/questions/46827674/
# ============================================================================
from typing import collections, List
import threading
class FooBar:
    
    def __init__(self, n):
        self.n = n
        self.lock_foo = threading.Lock()
        self.lock_bar = threading.Lock()
        self.lock_bar.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.lock_foo.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.lock_bar.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.lock_bar.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.lock_foo.release()
            

    def run(self, printFoo: 'Callable[[], None]', printBar: 'Callable[[], None]'):
        threading.Thread(target = self.foo, args=(printFoo,)).start()
        threading.Thread(target = self.bar, args=(printBar,)).start()



def printFoo():
    print("foo", end="")
    return
    
def printBar():
    print("bar", end="")
    return

FooBar(2).run(printFoo, printBar)


