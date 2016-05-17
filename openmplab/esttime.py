import sys, pdb, time, subprocess, math

USAGE="""
esttime.py -- A script to time program execution times for Lab4.

    $ python esttime.py PROG [N]

INPUT
  str PROG:
    Path to an executable that you want to time.
  int N: [5]
    Number of times to run the program. Defaults to 5.
OUTPUT
  Displays timing statistics after running program N times.

Example:
    $ python esttime.py ./seq
    Running './seq' 5 times...
    ...
    Mean: Std: Median:

    $ python esttime.py ./seq 10
    Running './seq' 10 times...
    ...
"""

# If you find any issues/bugs, feel free to report them to:
#   Eric Kim (erickim555@gmail.com )

# mean,_ss,pstdev are from:
#   http://stackoverflow.com/questions/15389768/standard-deviation-of-a-list
def mean(data):
    """Return the sample arithmetic mean of data."""
    n = len(data)
    if n < 1:
        raise ValueError('mean requires at least one data point')
    return sum(data)/float(n) # in Python 2 use sum(data)/float(n)
def _ss(data):
    """Return sum of square deviations of sequence data."""
    c = mean(data)
    ss = sum((x-c)**2 for x in data)
    return ss
def pstdev(data):
    """Calculates the population standard deviation."""
    n = len(data)
    if n < 2:
        raise ValueError('variance requires at least two data points')
    ss = _ss(data)
    pvar = ss/n # the population variance
    return pvar**0.5

def median(xs):
    """ Compute median of data. """
    xss = sorted(xs) # increasing
    ind = int(math.floor(len(xs)/2.))
    if (len(xs) % 2) == 0:
        return (xss[ind-1]+xss[ind])/2.
    else:
        return xss[ind]

def parse_args():
    if len(sys.argv) < 2:
        print "Error: Not enough input arguments."
        print USAGE
        exit(1)
    if sys.argv[1] in ('-h', '--help'):
        print USAGE
        exit(1)
    prog = sys.argv[1]
    if len(sys.argv) >= 3:
        N = sys.argv[2]
        try:
            N = int(N)
        except Exception as e:
            print "  Error: invalid N argument ({0}).".format(N)
            print "Exiting."
            exit(1)
    else:
        N = 5 # default
    return prog,N

def main():
    prog,N = parse_args()
    print "Running '{0}' {1} times...".format(prog,N)
    times = []
    for i in xrange(N):
        p = subprocess.Popen(prog, stdout=subprocess.PIPE, shell=True)
        (output, err) = p.communicate()
        line1 = output.split('\n')[0]
        func_time = float(line1.split(' ')[3])
        times.append(func_time)
        print "  [i={0}/{1}]: FUNC_TIME: {2}".format(i+1,N,func_time)

    mn = sum(times)/float(len(times))
    sig = pstdev(times)
    med = median(times)
    
    print "==== Statistics (in seconds) ===="
    print "Mean: {0} Std: {1} Median: {2}".format(mn,sig,med)
    print "  (Min: {0} Max: {1})".format(min(times), max(times))
    print "min(mean, median) = {0}".format(min(mn,med))
    
    print "Done."
if __name__ == '__main__':
    main()
