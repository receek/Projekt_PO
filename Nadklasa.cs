using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Net;
using System.Net.Sockets;

namespace ProjektPO{
    public class Nadklasa{
        public Frame Klatka = new Frame();
        public static IPHostEntry ipHost;
        public static IPAddress ipAddr;
        public static IPEndPoint localEndPoint;
        public static Socket sender;

        public static bool Init(string addressIP, string Port){
            try{
                ipAddr = System.Net.IPAddress.Parse(addressIP);
                localEndPoint = new IPEndPoint(ipAddr, Convert.ToInt32(Port));
                sender = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                IAsyncResult result = sender.BeginConnect(addressIP, Convert.ToInt32(Port), null, null);
                bool success = result.AsyncWaitHandle.WaitOne(1000, true);
                if (sender.Connected)
                    sender.EndConnect(result);
                else{
                    sender.Close();
                    throw new ApplicationException("Failed to connect server.");
                }
            }
            catch(Exception e){
                MessageBox.Show("Failed to connect server" + addressIP);
                return false;
            }
            return true;
        }

        public static string SendMessage(string Message){
            try{
                sender = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                sender.Connect(localEndPoint);
                byte[] messageSent = Encoding.ASCII.GetBytes(Message);
                int byteSent = sender.Send(messageSent);
                byte[] messageReceived = new byte[1024];
                int byteRecv = sender.Receive(messageReceived);
                return Encoding.ASCII.GetString(messageReceived, 0, byteRecv);
            }
            catch(Exception e){
                MessageBox.Show("Unexpected error with connection");
                //MessageBox.Show(e)
                return "-1\n";
            }
        }
    }
}