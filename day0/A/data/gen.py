from itertools import cycle
import random
import os
import datetime
import numpy as np

TASK_NUM = 1

R_LIMIT = 1000000
DELTA_LIMIT = 100000

def log(string):
	print(string, flush = True)
	with open("gen.log", "a") as f:
		f.write("[{}] {}\n".format(datetime.datetime.now(), string))

def genEmpty():
	return

def genSmall():
	return random.randint(2, 100), random.randint(99000, 100000)

def genLarge(dlim = 100):
	l = random.randint(DELTA_LIMIT, R_LIMIT - DELTA_LIMIT)
	return l, l + random.randint(DELTA_LIMIT - dlim, DELTA_LIMIT)

def genTestcase(filename, gen, **extra_param):
	log("Generating input for case {}, params: {} {}".format(filename, gen.__name__, extra_param))
	# assert ..., "Parameters invalid!"
	if not extra_param:
		l, r = gen()
	elif "l" in extra_param and "r" in extra_param:
		l = extra_param["l"]
		r = extra_param["r"]
	else:
		l, r = gen(**extra_param)
	with open("{}.in".format(filename), "w") as f:
		# f.write("{} {} {}\n{}\n".format(n, l, r, " ".join(list(map(str, s)))))
		f.write("{} {}\n".format(l, r))
	log("Generating output for case {}".format(filename))
	os.system('(time ../infinitesynthesis/std < {}.in > {}.ans) 2>> gen.log'.format(filename, filename))

class Cases:
	def __init__(self, prefix = ""):
		self.cnt = 0
		self.prefix = prefix
	
	def gen(self, gen, **extra_param):
		self.cnt += 1
		genTestcase("{}{}".format(self.prefix, self.cnt), gen, **extra_param)
	
	def skip(self, cnt = 1):
		self.cnt += cnt

os.system("rm gen.log")
testcase = Cases()
# precase = Cases("../pre/")
# sample = Cases("../down/")

for i in range(1, TASK_NUM + 1):
	log("Generating subtask {}".format(i))
	pre = testcase.cnt
	# pre_pre = precase.cnt
	# add testcases below
	
	testcase.gen(genEmpty, l = 100000, r = 200000)
	testcase.gen(genEmpty, l = 900000, r = 1000000)
	testcase.gen(genEmpty, l = 99991, r = 99991)
	testcase.gen(genEmpty, l = 99991, r = 99991 * 2)
	testcase.gen(genEmpty, l = 100003, r = 100003)
	testcase.gen(genEmpty, l = 666666, r = 666667)
	testcase.gen(genEmpty, l = 1, r = random.randint(99000, 100000))
	testcase.gen(genSmall)
	testcase.gen(genLarge, dlim = 10)
	testcase.gen(genLarge, dlim = 10)
	testcase.gen(genLarge, dlim = 1000)
	
	# add testcases above		
	log("Subtask {} done. ({} - {})".format(i, pre + 1, testcase.cnt))
	# log("Subtask {} done. (test: {} - {}; pre: {} - {})".format(i, pre + 1, testcase.cnt, pre_pre + 1, precase.cnt))

# for duck
# os.system("mkdir download")
# os.system("cp ../down/* ./download/")
