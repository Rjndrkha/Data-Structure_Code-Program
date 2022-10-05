import { StyleSheet, Text, TouchableOpacity, View} from 'react-native'
import React from 'react'
import { faMagnifyingGlass } from '@fortawesome/free-solid-svg-icons'
import { faBars } from '@fortawesome/free-solid-svg-icons'
import { faBagShopping } from '@fortawesome/free-solid-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { useNavigation } from '@react-navigation/native'

export default function Nav() {
    const navigation = useNavigation();
    return (
        <View style={styles.homeScreenHeader}>
            <TouchableOpacity onPress={()=>{alert("owo")}}><FontAwesomeIcon icon={faBars} size={22} color="black" /></TouchableOpacity>
            <View style={styles.headerRight}>
                <FontAwesomeIcon icon={faMagnifyingGlass} size={22} color="black" />
                <TouchableOpacity onPress={()=>{navigation.navigate("Cart")}}>
                    <FontAwesomeIcon icon={faBagShopping} size={22} color="black" />
                </TouchableOpacity>
            </View>
        </View>
    )
}

const styles = StyleSheet.create({
    homeScreenHeader: {
        // marginTop: 10,
        width: '100%',
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
    },
    headerRight: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        width: 60,
    },
})