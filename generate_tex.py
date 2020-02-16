import yaml

def printHeader():
    print('''\\documentclass[a4paper,10pt,onecolumn,notitlepage]{article}
\\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}
\\usepackage{setspace}
\\usepackage{listings, jlisting}
\\usepackage{colortbl}
\\title{Library for Competitive Programming}
\\author{morio\\_\\_}
\\lstset{
    language=C++,
    numbers=left,
    breaklines=true,
    basicstyle=\\tiny\\ttfamily,
    commentstyle={\\ttfamily \\color[cmyk]{1,0.4,1,0}},
    keywordstyle={\\ttfamily \\color[cmyk]{0.3,0.9,0,0}},
    stringstyle={\\ttfamily \\color[rgb]{0.8,0,0}},
    frame=tlRB,
    framesep=5pt,
}
\\begin{document}
\\maketitle
\\tableofcontents
''')

def printFooter():
    print('\\end{document}')

def isFile(f):
    return all(i in f for i in ['name', 'prefix', 'path'])

def printTag(tag, s):
    print("\\{}{{{}}}".format(tag, s))

def printFile(f, s):
    printTag(s, f['name'])
    print('\\lstinputlisting{{{}}}'.format(f['path']))

if __name__ == '__main__':
    printHeader()
    with open('lib.yml') as file:
        yml = yaml.load(file, Loader=yaml.SafeLoader)
        for k1 in yml:
            print("\\section{{{}}}".format(k1))
            if isFile(k1):
                exit(1)
            for k2 in yml[k1]:
                if isFile(k2):
                    printFile(k2, "subsection")
                else:
                    for k3 in k2:
                        print("\\subsection{{{}}}".format(k3))
                        for k4 in k2[k3]:
                            if not isFile(k4):
                                exit(1)
                            printFile(k4, "subsubsection")
    printFooter()
