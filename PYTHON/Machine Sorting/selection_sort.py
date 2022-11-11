def selectionsort(list3):
    for i in range(len(list3)-1):
        m_ind = i
        for j in range(i+1,len(list3)):
            if list3[j] < list3[m_ind]:
                m_ind = j
    
        if list3[i] != list3[m_ind]:
            list3[i],list3[m_ind] = list3[m_ind],list3[i]

