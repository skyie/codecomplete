#coding = utf8 


class Person(object):
    def __init__(self, name, sex):
        self.name = name
        self.sex = sex
        
    # birth,study,work abstract,implement by child
    def birth(self):
        pass
    def study(self):
        pass
    def work(self):
        pass
    #子类实现多态
    def life(self):
        self.birth()
        self.study()
        self.work()
class Poorman(Person):
    def __init__(self, name, sex):
        super(Poorman, self).__init__(name, sex)
    def birth(self):
        print("%s birth in a pool viliage" % self.name)
    def study(self):
        print("%s hasn't chance to sdudy in shchool" % self.name)
    def work(self):
        print("%s has no work,pool guy!" % self.name)
class Richman(Person):
    def __init__(self, name, sex):
        super(Richman, self).__init__(name, sex)
    #覆写父类的方法
    def birth(self):
        print("%s birth in a rich family,he is son of rich" % self.name)
    def study(self):
        print("%s sdudy in qinghua university" % self.name)
    def work(self):
        print("%s work in goverment,has much money!" % self.name)       
        
if __name__ == '__main__':
    poolman = Poorman('Tom', 'boy')
    richman = Richman('Lucy', 'girl')
    
    poolman.life()
    richman.life()