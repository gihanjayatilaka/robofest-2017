

int binaryEncodedIRReading(){
  int ans = 0;
  for (int i=0;i<6;i++){
    ans += reading[i]*(1<<(6-i));
  } 
  return ans;
}

bool isThisTheDestination(int boxColor){
  /*
  Harshana
  2017-9-4 7:30 P.M.


  Call me to see whether the robot has reached the destination
  (call when all the IR sensors give positive values OR IN SOME SUSPICOUS OCCATION {DISCUSS THIS})

  return:- true if destination. false o.w.
  
  if return false:
    robot will be at the position where the function was called
  if return true:
    robot will be at the position to drop the box
  */

  if (boxColor != getColorReading())
    return false;

  int andsum = (1<<7) - 1;
  int orsum = 0;
  for (int i=0; i<3;i++){
    readSensorLine(reading);
    andsum = andsum && binaryEncodedIRReading;
    orsum = orsum || binaryEncodedIRReading;
  }
  if (andsum == (1<<7) - 1){
    // perfectly matched all the points.
    // good place to unload the box

    // TODO: goback needed distance
    // return true;
  }else if (((andsum>>2)%2 == 1 or (andsum>>3)%2 == 1) and (orsum%2 == 1 or (orsum>>5)%2 == 1)){
    // now most probably destination is at a rotated position w.r.t robot
    // unlikely an arrow!!
    //THINGS TO DISCUSS:
    //  can 2 arrows give this

    // come back the half the distance that went
    // rotate a few steps
    // TO DISCUSS: HOW MUCH AND WHICH DIRECTION
    //comback the other half
    // + a few more steps

    // now return false :(
    // arrow follow will try ro align it
    // when 6IR condition is met this function will be called.
    // at the end it should be in the perfectly aligned position
  }

  //come back the distance that went forward for checking
  return false;
}
