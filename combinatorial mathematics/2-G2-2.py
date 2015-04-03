#coding=utf-8

CC = [([0]*12) for i in range(0,12)]

def init():
	CC[1][0]=1
	CC[1][1]=1
	
	for i in range(2,12):
		CC[i][0] = 1 
		for j in range(1,i):
			CC[i][j] = CC[i-1][j-1] + CC[i-1][j]
		CC[i][i] = 1

	print CC[9][4]*CC[11][7] + CC[11][6]*CC[9][4]

if __name__ == '__main__':
	init()

