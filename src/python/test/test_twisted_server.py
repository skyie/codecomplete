from twisted.internet import protocol, reactor
from time import ctime

PORT = 5555

class TCPServer(protocol.Protocol):
    def connectMade(self):
        client = self.clnt = self.transport.getPeer().host
        print "receive client..." , client
        
    def dataReceived(self, data):
        self.transport.write("[%s] %s" % (ctime(), data))
factory = protocol.Factory()

factory.protocol = TCPServer

print "wait connection..."
reactor.listenTCP(PORT, factory)
reactor.run()

