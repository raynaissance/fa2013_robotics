static class Utils
{
  /** Probability Density Function of a normal distribution. Gives the probability of x given the average and standard deviation */
  public static double normalPDF(double x, double mean, double stddev)
  {
    double result = pow((float)(x - mean), 2)/(2*pow((float)stddev, 2));
    result = exp(-1*(float)result);
    result = result/(sqrt(2*PI*pow((float)stddev, 2)));
    return result;
  }
}
