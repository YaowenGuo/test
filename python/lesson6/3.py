#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#Author:guoyaowen
#
import 
class Database(object):
    """Database Class supervises user information and database."""
    user = "root" #username
    password = "root" #user can set database password
    db_name = "my_dbname" #read database name from user
    charset = "utf-8"
    version = "1.0"
    ctime = "2016-01-01 00:00:00" #database created time
    mtime = "2016-01-01 00:00:00" #database modified time
    atime = "2016-01-01 00:00:00" #database accessed time
    grant_users = [user, ] #grant user who can visit this database
    tables = [] #database tables list
    __loged__ = False
    def __init__(self, db_name, user, pwd):
        """Initialize a database instance function
        Args: db_name, user, password
        Return: You define your own
        """
        self.db_name = db_name
        self.user = user
        self.password = pwd
        if self.check_login(self.db_name, self.user, self.password):
            #if the root user,load all database.if it is ordianry users,only
            #load the user's databases.
            __init__ = True
            
        else:
            #do something
            pass

    def check_login(self, db_name, user, pwd):
        """Check user login a database
        Args: db_name, user, password
        Return: True/False
        """
        #Find the user exists,if there is judged that the user's is correct, 
        #Correctly return true,return false error.
        result = False # return 
        try:
            file_object = open("db_config.ini","r")
            user_line = file_object.readline()
            while user_line:
                if(user in user_line):
                    self.user = user
                    self.password = user_line.split(':')[1].strip()
                    break
                user_line = file_object.readline()
            if(self.password == pwd):
                result = True
        except Exception,e:
            print e
        finally:
            file_object.close()
        return result

    def show_db_info(self):
        """Show database information
        contains: db_name, user, charset, ctime, mtime, atime
        """
        if (self.__loged__ == True):
            
        pass