import yaml

def print_prefix(l):
    print('\t\t"prefix": [')
    for i in l:
        print('\t\t\t"{}",'.format(i))
    print('\t\t],')

def print_body(l):
    print('\t\t"body": [')
    for i in l:
        print('\t\t\t"{}",'.format(i))
    print('\t\t],')

def print_library(title, prefix, body):
    print('\t"{}": {{'.format(title))
    print_prefix(prefix)
    print_body(body)
    print('\t},')

def get_body(path):
    body = []
    with open(path) as f:
        for s_line in f:
            s = s_line.rstrip()
            s = s.replace("\\n","\\\\\\\\n")
            s = s.replace('"','\\"')
            s = s.replace('\\ ','\\\\ ')
            s = s.replace('\\_', '\\\\_')
            body.append(s)
    return body

def isFile(f):
    return all(i in f for i in ['name', 'prefix', 'path'])

if __name__ == '__main__':
    with open('lib.yml') as file:
        yml = yaml.load(file, Loader=yaml.SafeLoader)
        libraries = []
        for k1 in yml:
            if isFile(k1):
                exit(1)
            for k2 in yml[k1]:
                if isFile(k2):
                    libraries.append(k2)
                else:
                    for k3 in k2:
                        for k4 in k2[k3]:
                            if not isFile(k4):
                                exit(1)
                            libraries.append(k4)
        print('{')
        for library in libraries:
            title, prefix, path = library['name'], library['prefix'], library['path']
            body = get_body(path)
            print_library(title, prefix, body)
        print('}')
