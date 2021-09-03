import subprocess
import sys

#argv[1] path to a file with videopaths and timestamps

fp = sys.argv[1]

videos = open(fp, "r").readlines()

count = len(videos)
ind = 0

join_file = open("join_file.txt", "w")

for v in videos:
    arg = v.split()
    out_vid = str(ind) + ".mp4"
    cmd = "ffmpeg -i " + arg[0] + " -ss " + arg[1] + " -to " + arg[2] + " -strict -2 " + out_vid
    subprocess.call([cmd], shell=True)

    join_file.writelines(["file " + "'" + out_vid + "'"])   
    join_file.write("\n")
    ind += 1

join_file.close()

cmd = "ffmpeg -f concat -safe 0 -i join_file.txt -c copy output.mp4"
subprocess.call([cmd], shell=True)



