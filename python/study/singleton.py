# python 单例的几种实现方式

# 1.使用模块
import threading
"""
Python 的模块就是天然的单例模式，
因为模块在第一次导入时，会生成 .pyc 文件，当第二次导入时，就会直接加载 .pyc 文件，而不会再次执行模块代码。
我们只需把相关的函数和数据定义在一个模块中，就可以获得一个单例对象了
"""
# 2.使用装饰器


def singleton_by_decorator(cls):
    """
    -定义了一个装饰器 singleton,它返回了一个内部函数 get_instance，
    该函数会判断某个类是否在字典 instances 中，
    如果不存在，则会将 cls 作为 key，cls(*args, **kwargs) 作为 value 存到 instances 中，
    否则，直接返回 instances[cls]
    """
    _instance = {}

    def get_instance(*args, **kwargs):
        if cls not in _instance:
            _instance[cls] = cls(*args, **kwargs)
        return _instance[cls]
    return get_instance


@singleton_by_decorator
class A(object):
    a = 1

    def __init__(self, x=0):
        self.x = x

# 3.使用类

# staticmethod


class Singleton(object):
    _instance_lock = threading.Lock()

    def __init__(self):
        import time
        time.sleep(1)

    @classmethod
    def get_instance(cls, *args, **kwargs):
        with Singleton._instance_lock:
            if not hasattr(Singleton, "_instance"):
                Singleton._instance = Singleton(*args, **kwargs)
        return Singleton._instance


# 4.__new__方法


class Singleton_New(object):
    _instance_lock = threading.Lock()

    def __init__(self):
        pass

    def __new__(cls, *args, **kwargs):
        if not hasattr(Singleton_New, "_instance"):
            with Singleton_New._instance_lock:
                if not hasattr(Singleton_New, "_instance"):
                    Singleton_New._instance = object.__new__(cls)
        return Singleton_New._instance

# 5-metaclass


class test(object):
    def __init__(self):
        print("this is init method")

    def __new__(self):
        print("this is new method")

    def __call__(self, *args, **kwargs):
        print("this is call method")


def task(arg):
    obj = Foo("name")
    print(obj)


class SingletonType(type):
    _instance_lock = threading.Lock()

    def __call__(cls, *args, **kwargs):
        if not hasattr(cls, "_instance"):
            with SingletonType._instance_lock:
                if not hasattr(cls, "_instance"):
                    cls._instance = super(
                        SingletonType, cls).__call__(*args, **kwargs)
        return cls._instance


class Foo(metaclass=SingletonType):
    def __init__(self, name):
        self.name = name


if __name__ == "__main__":
    for i in range(10):
        t = threading.Thread(target=task, args=[i, ])
        t.start()
    t = test()
    
