#include <EtherCard.h>

#define STATIC 1  // set to 1 to disable DHCP (adjust myip/gwip values below)

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
static byte myip[] = { 192,168,1,203 };

// gateway ip address
static byte gwip[] = { 192,168,1,1 };

// LED to control output
int ledPin10 = 10;
BufferFiller bfill;
byte Ethernet::buffer[700];


static word homePage() 
{
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 503 Service Unavailable\r\n"
    "Content-Type: text/html\r\n"
    "Retry-After: 600\r\n"
    "\r\n"
    "<html>"
      "<head><title>"
         "Servers de Leds"
        "</title></head>"
    "<body>"
    "<h3>Bienvenido a Arduino</h3>"
    "<p><em>"
      "Este es nuestro primer proyecto.<br />"
      "<p>Luz: <a href=\"/LEDON\">On</a> <a href=\"/LEDOFF\">Off</a> </p>."
    "</em></p>"
    "</body>"
    "</html>"
    )); 
  return bfill.position();
}

static word luzOn() 
{
  digitalWrite(ledPin10, HIGH);
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 503 Service Unavailable\r\n"
    "Content-Type: text/html\r\n"
    "Retry-After: 600\r\n"
    "\r\n"
    "<html>"
      "<head><title>"
         "Servers de Leds"
        "</title></head>"
    "<body>"
    "<h3>Bienvenido a Arduino</h3>"
    "<p><em>"
      "Luz encendida.<br />"
      "<p>Luz: <a href=\"/\">atras</a> </p>."
    "</em></p>"
    "</body>"
    "</html>"
    )); 
  return bfill.position();
}

static word luzOff() 
{
  digitalWrite(ledPin10, LOW);
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 503 Service Unavailable\r\n"
    "Content-Type: text/html\r\n"
    "Retry-After: 600\r\n"
    "\r\n"
    "<html>"
      "<head><title>"
         "Servers de Leds"
        "</title></head>"
    "<body>"
    "<h3>Bienvenido a Arduino</h3>"
    "<p><em>"
      "Luz encendida.<br />"
      "<p>Luz: <a href=\"/\">atras</a> </p>."
    "</em></p>"
    "</body>"
    "</html>"
    )); 
  return bfill.position();
}

void setup () {
  pinMode(ledPin10, OUTPUT);

  Serial.begin(9600);
  Serial.println("Trying to get an IP...");

  Serial.print("MAC: ");
  for (byte i = 0; i < 6; ++i) {
    Serial.print(mymac[i], HEX);
    if (i < 5)
      Serial.print(':');
  }
  Serial.println();
  
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println( "Failed to access Ethernet controller");

#if STATIC
  Serial.println( "Getting static IP.");
  if (!ether.staticSetup(myip, gwip)){
    Serial.println( "could not get a static IP");
  
  }
#else

  Serial.println("Setting up DHCP");
  if (!ether.dhcpSetup()){
    Serial.println( "DHCP failed");   
  }
#endif
  
  ether.printIp("My IP: ", ether.myip);
  ether.printIp("GW IP: ", ether.gwip);
  ether.printIp("DNS IP: ", ether.dnsip);
}

void loop () 
{
 
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  
  
  // IF LED10=ON turn it ON
  if(strstr((char *)Ethernet::buffer + pos, "GET /LEDON") != 0) 
  {
      Serial.println("Received ON command");
      digitalWrite(ledPin10, HIGH);
      ether.httpServerReply(luzOn());
  }

  // IF LED10=OFF turn it OFF  
  if(strstr((char *)Ethernet::buffer + pos, "GET /LEDOFF") != 0) 
  {
      Serial.println("Received OFF command");
      ether.httpServerReply(luzOff());
   }
    
   if (pos)  // check if valid tcp data is received
    ether.httpServerReply(homePage()); // send web page da
 
}



