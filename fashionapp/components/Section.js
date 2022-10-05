import { FlatList, StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native'
import React from 'react'
import { useNavigation } from '@react-navigation/native'

export default function Section({ section, data }) {
    const navigation = useNavigation()
    const turncate = (str, n) => {
        return str?.length > n ? str.substr(0, n - 1) + "..." : str;
    }

    return (
        <View style={styles.sectionScreen}>
            <View style={styles.header}>
                <Text style={{ fontWeight: 'bold', fontSize: 20 }}>{section}</Text>
                <TouchableOpacity onPress={() => navigation.navigate("SeeAll",
                    {
                        category: section,
                        data: data
                    })}>
                    <Text style={{ color: 'orange', fontSize: 12 }}>See All</Text></TouchableOpacity>
            </View>
            <View style={{ justifyContent: 'center', alignItems: 'center' }}>
                <FlatList
                    data={data.splice(0, 4)}
                    keyExtractor={id => data.id}
                    renderItem={({ item }) => (
                        <View>
                            <TouchableOpacity activeOpacity={0.8} onPress={() => navigation.navigate("Item", {
                                item: item
                            })}>
                                <Image source={item.image} style={styles.categoryImage} />
                            </TouchableOpacity>
                            <View style={{ padding: 10 }}>
                                <Text style={{ fontSize: 12, fontWeight: 'bold' }}>{turncate(item.name, 15)}</Text>
                                <View style={{ flexDirection: "row" }}>
                                    <Text style={{ fontSize: 12, color: 'orange', fontWeight: 'bold' }}>$</Text>
                                    <Text style={{ fontSize: 15, fontWeight: 'bold' }}>{item.price}</Text>
                                </View>
                            </View>
                        </View>
                    )}
                    numColumns={2}
                ></FlatList>
            </View>
        </View>
    )
}

const styles = StyleSheet.create({
    sectionScreen: {
        flexGrow: 1,
        marginTop: 35,
    },
    header: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
        alignContent: 'center',
        marginBottom: 10
    },
    categoryImage: {
        width: 130,
        height: 200,
        margin: 7,
        resizeMode: 'contain',
        backgroundColor: 'white',
        borderRadius: 10
    }
})