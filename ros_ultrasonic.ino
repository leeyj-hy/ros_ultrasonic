std_msgs::Float64 int_msg;
ros::Publisher chatter("chatter", &int_msg);
#define 2 TRIG
#define 3 ECHO

int int_msg
long duration, distance;


void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  pinMode(TRIG, OUTPUT)
  pinMode(ECHO, INPUT);
}

void loop()
{  digitalWrite(TRIG, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG, LOW);

   digitalWrite(TRIG, LOW);

   duration = pulseIn(ECHO, HIGH);

   distance = duration * 17/1000;
   
  int_msg.data = distance;
  chatter.publish( &int_msg );
  nh.spinOnce();
  delay(1000);
}
