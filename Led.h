/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com
*
*   06/11/2023
*
*/
class Led{
  public:
    Led(int red, int blue, int green){
      rojo = red;
      azul = blue;
      verde = green;
    }
    void control(double t){
      int r2,v2,a2;
      if(t <= 30){
        r2 = 150;
        v2 = 150;
        a2 = 150;
      }else if(t > 70){
        r2 = 255;
        v2 = 0;
        a2 = 0;
      }else if(t > 30  && t <= 40){
        r2 = 0;
        v2 = 0;
        a2 = 188;
      }else if(t > 40 && t <= 50){
        r2 = 0;
        v2 = 199;
        a2 = 0;
      }else if(t > 50 && t <= 60){
        r2 = 255;
        v2 = 100;
        a2 = 10;
      }else if(t > 60 && t <= 70){
        r2 = 156;
        v2 = 9;
        a2 = 15;
      }

      if(r == r2 && v == v2 && a == a2)
        Serial.println("XD");
      else
        color(r2, v2, a2);
  }

  void color(int r2, int v2, int a2){
    int i, men1, men2, mayor = 0;
    int nega[3], temp[3];

    temp[0] = r2-r;
    temp[1] = v2-v;
    temp[2] = a2-a;

    for(i=0;i<3;i++){
      if(temp[i] < 0){
        temp[i] = -1*temp[i];
        nega[i] = 1;
      }
      else
        nega[i] = 0;
    }

    for(i=0;i<3;i++)
      if(mayor<temp[i])
        mayor = temp[i];

    for(i=0;i<mayor;i++){
      analogWrite(rojo, r);
      analogWrite(verde, v);
      analogWrite(azul, a);

    if(mayor == temp[0]){
      men1 = mayor/temp[1];
      men2 = mayor/temp[2];
      if(i%men1 == 0 && v!=v2)
        if(nega[1] == 0)
                    v++;
        else
          v--;        
      if(i%men2 == 0 && a!=a2)
        if(nega[2] == 0)
                    a++;
        else
          a--;
      if(nega[0] == 0)
        r++;
                else
        r--;
      }else if(mayor == temp[1]){
          men1 = mayor/temp[0];
                  men2 = mayor/temp[2];
          if(i%men1 == 0 && r!=r2)
            if(nega[0] == 0)
              r++;
                        else
              r--; 
          if(i%men2 == 0 && a!=a2)
            if(nega[2] == 0)
              a++;
            else
                        a--;
          if(nega[1] == 0)
            v++;
          else
            v--; 
        }else{
          men1 = mayor/temp[0];
          men2 = mayor/temp[1];
          if(i%men1 == 0 && r!=r2)
            if(nega[0] == 0)
              r++;
            else
              r--;        
          if(i%men2 == 0 && v!=v2)
            if(nega[1] == 0)
              v++;
            else
              v--;
          if(nega[2] == 0)
            a++;
          else
            a--;
        }
      delay(15);
      }
    }
  private:
    int rojo, azul, verde, r = 0, a = 0, v = 0;
};