import sys
import os

def copy(file1, file2):
	f1 = open(file1, "r")
	f2 = open(file2, "w")
	for line in f1:
	    f2.write(line)
	f1.close()
	f2.close()
	
		
def equal(file1, file2):
	f1 = open(file1,"r")
	f2 = open(file2,"r")
	a = set(f1.readlines())
	b = set(f2.readlines())
	f1.close()
	f2.close()
	return a == b
	
def main():
	argv = sys.argv
	passed = True
	test_inp = argv[1]
	correct_out = argv[2]
	
	copy_inp = "tmpA.txt"
	our_out = "tmpB.txt"
	copy(test_inp, copy_inp)
		
	os.system( "build/sorter " + copy_inp + " >> " + our_out )
		
	log = argv[1][:-3] + ".log"
	lg = open(log, "w")
	if equal(our_out,correct_out):
		print(argv[1][:-3] + " OK")
		lg.write("OK")
	else:
		print(argv[1][:-3] + " FAILURE")
		passed = False
		lg.write("FAILURE")
	lg.close()
    	
	path = os.path.join(os.path.abspath(os.path.dirname(__file__)), copy_inp)
	os.remove(path)
	path = os.path.join(os.path.abspath(os.path.dirname(__file__)), our_out)
	os.remove(path)
	
	if (not os.path.exists("log.txt")):
		main_log = open("log.txt","w")
		main_log.write("OK")
		main_log.close()
		
	main_log = open("log.txt","r")
	if(main_log.read() == "OK"):
		main_log.close()
		if(passed):
			main_log = open("log.txt","w")
			main_log.write("OK")
			main_log.close()
		else:
			main_log = open("log.txt","w")
			main_log.write("FL")
			main_log.close()
		
	else:
		main_log.close()

if __name__ == "__main__":
    main()
