stack = []

string = raw_input("Enter the string")

def check_priority(a, b):
	#do ascii value comparision here decide priority
	if(a=='*' and b=='*'):
		return 0;
	elif(a=='*' and b=='/'):
		return 0;
	elif(a=='/' and b=='*'):
		return 0;
	elif(a=='/' and b=='/'):
		return 0;
	else:
		return 1;

def calculate(a, b, s):
	if(s=='+'):
		return b+a;
	if(s=='-'):
		return b-a;
	if(s=='/'):
		return b/a;
	if(s=='*'):
		return b*a;

output = ''
for i in range(0, len(string)):
	if(string[i] in '0123456789'):
		output+=string[i]
		#print output
	else:
		if(string[i]==')'):
			while(stack[-1]!='('):
				output=output + ' '+stack.pop()
			stack.pop()
		else:
		#if priority of stack[-1] >= string[i] - pop till you get the priority right 
			if(len(stack)==0 or check_priority(stack[-1], string[i])==1):
				stack.append(string[i])
				output+=' '
				#print "running", string[i]
			elif(len(stack)!=0):
				while(len(stack)!=0):
					if(check_priority(stack[-1], string[i])!=0):
						break;
					try:
						#print "removing from stack"
						output=output+ ' ' +stack.pop()
					except:
						print "stack empty"
				stack.append(string[i])
	
		print "Stage", i
		print stack
		print output

while(len(stack)!=0):
	output=output+' '+stack.pop()

print "Final answer"
print output.split()

result = output.split()
cal = []


for i in range(0, len(result)):
	try:
		temp = int(result[i])
		cal.append(temp)
	except:
		a = cal.pop()
		b = cal.pop()
		cal.append(calculate(a, b, result[i]))

print "Calculation Result", cal[0]

		
