from twisted.internet import protocol, reactor
from time import ctime


HOST = "localhhost"
PORT = 5555
class TCPClient(protocol.Protocol):
    def sendData(self):
        data = raw_input("<")
        if data :
            print "send data %s ..." %(data)
            self.transport.write(data)
        else:
            self.transport.loseConnection()
        
    def connectMade(self):
        self.sendData()
    def dataReceived(self):
        print data
        self.sendData()

class TCPFatory(protocol.ClientFactory):
    protol = TCPClient
    
reactor.connectTCP(HOST, PORT, TCPFatory())
reactor.run()
            