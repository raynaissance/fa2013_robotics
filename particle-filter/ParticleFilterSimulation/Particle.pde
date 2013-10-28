class Particle {
  public double x;
  public double y;
  private double weight = 0; // Probability of the robot being this particle
  private double preWeight = 0; // weight before being multiplied by N
  private boolean isRobot;
  private double speed = 30; // px/sec

  Particle(double xloc, double yloc, boolean isRobot) {
    x = xloc;
    y = yloc;
    this.isRobot = isRobot;
  } 
  
  /** Used to set the particle weight right after being created */
  public void setWeight(double weight)
  {
    this.weight = weight;
  }
  
  public double getWeight()
  {
    return weight;
  }

  /** Used to calculate the weight before being multipled by N */
  public double calculatePreWeight(double sensorReading, KeyNames sensorDirection, double sensorNoise) {
    if (sensorDirection == KeyNames.UPARROW)
    {
      preWeight = Utils.normalPDF(sensorReading, y, sensorNoise);
    }
    if (sensorDirection == KeyNames.DOWNARROW)
    {
      preWeight = Utils.normalPDF(sensorReading, ParticleFilterSimulation.windowHeight - y, sensorNoise);
    }
    if (sensorDirection == KeyNames.LEFTARROW)
    {
      preWeight = Utils.normalPDF(sensorReading, x, sensorNoise);
    }
    if (sensorDirection == KeyNames.RIGHTARROW)
    {
      preWeight = Utils.normalPDF(sensorReading, ParticleFilterSimulation.windowWidth - x, sensorNoise);
    }
    
    // At this point, preWeight is only P(sensor reading | robot @ location), 
    // so it must be multiplied by P(robot @ location), which is the weight
    println("Finalizing preweight: preweight = " + preWeight + " weight = " + weight);
    preWeight = preWeight*weight;
    return preWeight;
  }
  
  public void calculateWeight(double N)
  {
    weight = preWeight*N;
  }

  public void update(HashMap<KeyNames, Boolean> keyStates, double frameTime) {
    double d = 0;
    double theta = 0;
    
    if (keyStates.get(KeyNames.W)) { theta = 270; d = speed*frameTime; }
    if (keyStates.get(KeyNames.A)) { theta = 180; d = speed*frameTime; }
    if (keyStates.get(KeyNames.S)) { theta = 90; d = speed*frameTime; }
    if (keyStates.get(KeyNames.D)) { theta = 0; d = speed*frameTime; }
    
    if (d > 0)
    {
      double actualTheta = theta + randomNormal(20);
      double actualDistance = d + randomNormal(2);
      x = x + actualDistance*cos(PI/180*(float)actualTheta);
      y = y + actualDistance*sin(PI/180*(float)actualTheta);
    }
    
    drawSelf();
  }

  public void drawSelf() {
    if (isRobot) {
      fill(255,100,0);
      ellipse((float)x, (float)y, 8, 8);
    } else {
      fill(255);
      ellipse((float)x, (float)y, 1, 1);
    }
    
    // Display the particle's weight next to it (only works for small numbers of particles)
    //text("" + round((float)weight*1000), (float)x, (float)y); 
  }

  double randomNormal(double s) {
    double sum = 0;
    for (int i=0; i<12; i++) {
      sum += (random(0, 1))*2*s - s;
    }
    return sum/2;
  }
  
  
}

