from itertools import combinations

lst = [
        ["100","ryan","music","2"],
        ["200","apeach","math","2"],
        ["300","tube","computer","3"],
        ["400","con","computer","4"],
        ["500","muzi","music","3"],
        ["600","apeach","music","2"]
    ]

def examine_each_case(relation, cases):
     # 각 case 마다 같은게 있는지 

    candidate_case = []
    # candidate_data_case = []

    for case in list(cases):
        # print(case)
        
        # 이 케이스가 가능한지
        possible = True
        data_lst = []

        #각 case안에 있는 값 하니씩 보기
        for row in relation:

            # 전체 데이터를 보면서 그 튜플이 이미 있으면(중복됨) break -> 그  case 버리기

            tup = () # 각 행의 튜플에 맞는 데이터
            for x in case:
                tup += (row[x],)

            if tup in data_lst:
                possible = False
                break
                
            data_lst.append(tup)
            
            if possible == False:   # 더이상 데이터 볼필요x
                break
        
        if possible:
            candidate_case.append(case)

    return candidate_case

def isin(curr_tup, prev):
    # curr_tup - 하나짜리
    # prev - 여러개짜리

    # tup이 하나라도 curr_tup 이 있으면 이 cur_tup은 최소성 만족 X 
    # 1,2/2,4/3,4

    
    for tup in prev:
        # 튜플 안의 데이터

        include = True
        # 튜플이니까 둘다 curr_tup안에 있어야 있는거
        # 둘다 만족하는게 있으면 이건 최소성아님
        # (1,2) False
        # (2,4) Fasle
        # (3,4) True
        # 하나라도 false면 이 데이터는 통과
        for data in tup:
            if data not in curr_tup: # 1,3,4
                # print(curr_tup)
                include = False
                break

        if include == True:
            return True
    
    return False


def solution(relation):
    answer = 0
    columns = [x for x in range(0,len(relation[0]))]

    
    ans = []
    # 경우의 수 만들기
    for i in range(1,len(relation[0])+1):

        cases = combinations(columns, i) # print(list(cases))
        curr = examine_each_case(relation, cases)

        
        if len(ans) == 0:
            ans = curr
        else:
            # 최소인지 검사
            for curr_tup in curr:
                if isin(curr_tup, ans) == False:
                    # print(curr_tup)
                    ans.append(curr_tup)

    # print(ans)
    print(len(ans))

    return answer

solution(lst)