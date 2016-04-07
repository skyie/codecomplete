# -*- coding: utf-8 -*- 



import sqlalchemy as sa
import sqlalchemy.orm as orm
from sqlalchemy.ext.declarative import declarative_base



Base = declarative_base()


class User(Base):

    __tablename__ = 'user'
    id = sa.Column(sa.String(20), primary_key=True)
    name = sa.Column(sa.String(20))

    address = orm.relationship('Address',  back_populates='user')
class Address(Base):
    
    __tablename__ = 'address'
    id = sa.Column(sa.String(20), primary_key=True)
    email_address = sa.Column(sa.String(20), nullable=False)
    user_id = sa.Column(sa.String(20), sa.ForeignKey('user.id'))
    
    #user = orm.relationship('User', back_populates='address')
    
    def __reqr__(self):
        return "<Address email_address(%s)>" % (self.email_address)

engine = sa.create_engine('mysql+mysqlconnector://root:sangfor@localhost:3306/test')

DBSession = orm.sessionmaker(bind=engine)

if __name__ == '__main__':
    session = DBSession()

    new_user = User(id='5', name='Bob')
    address = Address(id='1', email_address='322@qq.com')
    new_user.address = address
    session.add(new_user)

    session.commit()

    session.close()
    
