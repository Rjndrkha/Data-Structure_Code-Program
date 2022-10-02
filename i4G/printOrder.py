import time
        
class Foo(object):
    def __init__(self):
        pass


    def first(self, printFirst):
        """
        :type printFirst: method
        :rtype: void
        """
        # first fires immediately"
        printFirst()


    def second(self, printSecond):
        """
        :type printSecond: method
        :rtype: void
        """
        time.sleep(0.1);
        # second is delayed for 0.1 milli second
        printSecond()
            
            
    def third(self, printThird):
        """
        :type printThird: method
        :rtype: void
        """
        time.sleep(0.2)
        # third fires after 0.2 milli second 
        printThird()