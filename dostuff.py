f = open("myIDirect3DDevice9.cpp", "r")

file = f.read()
startsearch=0


foundindex = file.find("myIDirect3DDevice9::", startsearch)

while foundindex != -1:
	foundindex = foundindex + len("myIDirect3DDevice9::")
	endindex1 = file.find("(", foundindex)
	endindex2 = file.find(" ", foundindex)
	endindex = min(endindex1, endindex2)
	funcname = file[foundindex:endindex]
	funcstartindex = file.find("{", endindex+1)
	file = file[0:funcstartindex] + "{\n#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS\n\tOutputDebugString(\"myIDirect3DDevice9::" + funcname + " called!\");\n#endif" + file[funcstartindex+1:]
	startsearch = funcstartindex + len("{\n#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS\n\tOutputDebugString(\"myIDirect3DDevice9::")
	foundindex = file.find("myIDirect3DDevice9::", startsearch)
	
print(file)

f.close()