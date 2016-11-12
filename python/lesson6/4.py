#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#Author:GuoYaoWen

class Item(object):
    """Item is The list of all goods."""
    def __init__(self):
        self.goods = []

    def add_goods(self, goods):
        self.goods.append(goods)

    def show_goods(self):
        for goods in self.goods:
            print goods,
        print 


class   Cart(object):
    """Cart has all goods """
    def __init__(self,name):
        self.name = name
        self.goods_list = []

    def add_goods(self, goods):
        self.goods_list.append(goods)

    def show_goods(self):
        for goods in self.goods_list:
            print goods,
        print 

        
class User(object):
    """Users supermarket customers can creat a shopping 
    cart,the purchase of goods.Show cart iformation."""
    def __init__(self, user):
        super(User, self).__init__()
        self.name = user
        self.cart_list = {}

    # def __repr__(self):
    #     return self
    def add_cart(self,cart):
        
        self.cart_list[cart] = Cart(cart)

    def has_cart(self):
        if (len(self.cart_list) == 0):
            return False
        else:
            return True

    def add_goods(self, cart, goods):
        self.cart_list[cart].add_goods(goods)

    def show_cart(self):
        for key in self.cart_list:
            print "in cart %s,goods is:" % key
            self.cart_list[key].show_goods()


if __name__ == '__main__':
        user = None
        item = Item()
        while True:
            print "Input 1,add goods"
            print "Input 2,create a user"
            print "Input 3,create a cart"
            print "Input 4,add good to cart"
            print "Input 5,show all cart goods list"
            select  = raw_input("Please enter a number:")
            select = int(select)
            
            
            if (select == 1):
                goods  =  raw_input('Please input a goods name add into Item:')
                item.add_goods(goods)
                item.show_goods()
            elif(select == 2):
                user = raw_input('Please enter a user name, the system will create an account for the user:')
                user = User(user)
                user.show_cart()
            elif(select == 3):
                print user
                if(user == None):
                    print 'You must be logged in to create a shopping chart!Please select 2 to create a Account.'
                else:
                    user.add_cart(str(len(user.cart_list)) )
            elif(select == 4):
                if (user == None):
                    print 'You must be logged in to create a shopping chart!Please select 2 to create a Account.'
                else:
                    if user.has_cart():
                        item.show_goods()
                        goods = raw_input('Please enter your choose to buy goods:'  )
                        print "all cart is ",
                        for key in user.cart_list:
                            print key
                        cart = raw_input("Which cart would you put it in:")
                        user.add_goods(cart, goods)
                    else:
                        print 'Your do not have s shopping cart,please choose three to create a shopping cart.'
            elif(select == 5):
                if(user == None):
                    print 'You must be logged in to create a shopping chart!Please select 2 to create a Account.'
                else:
                    user.show_cart()
            else:
                print "select error ,Please input 1~5"






