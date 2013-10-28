Particle robot;
ArrayList<Particle> particles;
int numParticles = 500;

public static final int windowWidth = 640;
public static final int windowHeight = 360;
private HashMap<KeyNames, Boolean> keyStates = new HashMap<KeyNames, Boolean>();

PersistentLine laserLine = new PersistentLine(0,0,0,0);

void setup() {
  size(windowWidth, windowHeight);
  noStroke();
  particles = new ArrayList<Particle>();
  
  for(int i=0; i<numParticles; i++) {
    Particle p = new Particle(windowWidth/2,windowHeight/2, false);
    particles.add(p);
  }
  
  robot = new Particle(windowWidth/2,windowHeight/2, true);
  
  // Give each particle equal weight = 1/(number of particles)
  for (Particle p : particles)
  {
    p.setWeight(1.0/particles.size());
  }
  
  for (KeyNames keyName : KeyNames.values())
  {
    keyStates.put(keyName, false);
  }
}

void draw() {
  background(102);
  fill(255);
  textSize(16);
  text("Frame rate: " + int(frameRate), 10, 20);
  text("\nKey:", 10, 20);
  text("\n\n Orange - Robot actual position. \n White - Particle. \n Blue - Mean particle.", 20, 20);
  
  double xSum = 0;
  double ySum = 0;
  
  // Update particles
  for (Particle p : particles)
  {
    xSum += p.x;
    ySum += p.y;
    p.update(keyStates, 1/(double)frameRate);
  }
  
  // Update robot
  robot.update(keyStates, 1/(double)frameRate);
  stroke(255, 0, 0);
  laserLine.drawLine();
  noStroke();
  
  // Draw the mean particle position in blue
  fill(0,0,255);
  ellipse((float)xSum/particles.size(), (float)ySum/particles.size(), 5, 5);
  
  // Draw the laser from the sensor if it's being used
  KeyNames laserDirection = null;
  double sensorReading = -1;
  if (keyStates.get(KeyNames.UPARROW)) { laserDirection = KeyNames.UPARROW; keyStates.put(laserDirection, false); }
  if (keyStates.get(KeyNames.DOWNARROW)) { laserDirection = KeyNames.DOWNARROW; keyStates.put(laserDirection, false); }
  if (keyStates.get(KeyNames.LEFTARROW)) { laserDirection = KeyNames.LEFTARROW; keyStates.put(laserDirection, false); }
  if (keyStates.get(KeyNames.RIGHTARROW)) { laserDirection = KeyNames.RIGHTARROW; keyStates.put(laserDirection, false); }
  
  if (laserDirection != null)
  {
    // Draw the laser line and calculate the sensor reading
    if (laserDirection == KeyNames.UPARROW) { laserLine = new PersistentLine((float)robot.x, (float)robot.y, (float)robot.x, (float)0); 
                                              sensorReading = robot.y; }
    if (laserDirection == KeyNames.DOWNARROW) { laserLine = new PersistentLine((float)robot.x, (float)robot.y, (float)robot.x, (float)ParticleFilterSimulation.windowHeight);
                                                sensorReading = ParticleFilterSimulation.windowHeight - robot.y; }
    if (laserDirection == KeyNames.LEFTARROW) { laserLine = new PersistentLine((float)robot.x, (float)robot.y, (float)0, (float)robot.y); 
                                                sensorReading = robot.x; }
    if (laserDirection == KeyNames.RIGHTARROW) { laserLine = new PersistentLine((float)robot.x, (float)robot.y, (float)ParticleFilterSimulation.windowWidth, (float)robot.y);
                                                 sensorReading = ParticleFilterSimulation.windowWidth - robot.x; }
    println("Sensor reading was " + sensorReading);
    
    // Have each particle calculate its pre-weight while summing them up to calculate N
    double N = 0;
    for (Particle p : particles)
    {
      double preWeight =  p.calculatePreWeight(sensorReading, laserDirection, 5); // Number is the sensor std dev
      N += preWeight; 
    }
    
    N = 1/N; // N is now calculated - give it to the particles so that they can calculate their actual weight
    
    for (Particle p : particles)
    {
      p.calculateWeight(N);
    }
    
    // Now we can do particle filtering
    // First, sort the particles by weight (smallest to largest)
    // We know that all numbers are between 0 and 1, non-repeating
    ArrayList<Particle> sortedParticles = new ArrayList<Particle>();

    while (particles.size() > 0)
    {
      int minIndex = 0;
      double minVal = particles.get(0).getWeight();
      
      for (int i=0; i<particles.size(); i++)
      {
        Particle p = particles.get(i);
        if (p.getWeight() < minVal)
        {
          minVal = p.getWeight();
          minIndex = i;
        }
      }
      
      sortedParticles.add(particles.remove(minIndex));
    }
    
    // sortedParticles now has all of the particles sorted by weight
    double[] filterWeights = new double[sortedParticles.size()];
    // Transfer weights into filterWeights from sortedParticles, maintaining the order
    // When transferring a weight to filterWeights, add the previous filterWeight weight to the current one so that the last filterWeight will be 1
    filterWeights[0] = sortedParticles.get(0).getWeight(); 
    for (int i=1; i<sortedParticles.size(); i++)
    {
      filterWeights[i] = sortedParticles.get(i).getWeight() + filterWeights[i-1];
    }
    
    // Now get a random number from 0 to 1, it corresponds to the particle that corresponds to some weight in filterWeights, where the random number
    // is > the previous weight and <= that weight
    particles.clear();
    
    for (int i=0; i<sortedParticles.size(); i++)
    {
      double randNum = random(1);
      
      if (randNum <= filterWeights[0])
      {
        Particle sourceParticle = sortedParticles.get(0);
        Particle newParticle = new Particle(sourceParticle.x, sourceParticle.y, false);
        newParticle.setWeight(sourceParticle.getWeight());
        particles.add(newParticle); // Particles aren't removed b/c they can be resampled multiple times
      } else {
        for (int j=1; j<sortedParticles.size(); j++)
        {
          if (randNum <= filterWeights[j])
          {
            Particle sourceParticle = sortedParticles.get(j);
            Particle newParticle = new Particle(sourceParticle.x, sourceParticle.y, false);
            newParticle.setWeight(sourceParticle.getWeight());
            particles.add(newParticle);
            break; // Get a new random number
          }
        }
      }
    }
    
    for (Particle p : particles)
    {
      println("Resampled particle at: " + p.x + ", " + p.y);
    }
  }
}

void keyPressed()
{
  if (key == CODED)
  {
    if (keyCode == UP) { keyStates.put(KeyNames.UPARROW, true); }
    if (keyCode == DOWN) { keyStates.put(KeyNames.DOWNARROW, true); }
    if (keyCode == LEFT) { keyStates.put(KeyNames.LEFTARROW, true); }
    if (keyCode == RIGHT) { keyStates.put(KeyNames.RIGHTARROW, true); }
  } else {
    if (key == 'w') { keyStates.put(KeyNames.W, true); }
    if (key == 'a') { keyStates.put(KeyNames.A, true); }
    if (key == 's') { keyStates.put(KeyNames.S, true); }
    if (key == 'd') { keyStates.put(KeyNames.D, true); }
  }
}

void keyReleased()
{
  if (key == CODED)
  {
    if (keyCode == UP) { keyStates.put(KeyNames.UPARROW, false); }
    if (keyCode == DOWN) { keyStates.put(KeyNames.DOWNARROW, false); }
    if (keyCode == LEFT) { keyStates.put(KeyNames.LEFTARROW, false); }
    if (keyCode == RIGHT) { keyStates.put(KeyNames.RIGHTARROW, false); }
  } else {
    if (key == 'w') { keyStates.put(KeyNames.W, false); }
    if (key == 'a') { keyStates.put(KeyNames.A, false); }
    if (key == 's') { keyStates.put(KeyNames.S, false); }
    if (key == 'd') { keyStates.put(KeyNames.D, false); }
  }
}

