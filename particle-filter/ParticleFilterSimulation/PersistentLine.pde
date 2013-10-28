// This is used to make sure the laser range finder line is visible on screen by ensuring it is drawn for a sufficient amount of time

class PersistentLine
{
  private float x1, x2, y1, y2;
  private long birthTime = 0;
  private final long lifeSpan = 150; // ms
  
  public PersistentLine(float x1, float y1, float x2, float y2)
  {
    this.x1 = x1;
    this.x2 = x2;
    this.y1 = y1;
    this.y2 = y2;
    this.birthTime = System.currentTimeMillis();
  }
  
  public void drawLine()
  {
    if (System.currentTimeMillis() < birthTime + lifeSpan)
    {
      line(x1, y1, x2, y2);
    }
  }
}
