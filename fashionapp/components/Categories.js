import { StyleSheet, Text, View, Image, FlatList, ScrollView } from 'react-native'
import React, {
} from 'react'

export default function Categories({ categories }) {

    return (
        <View style={styles.categoriesScreen}>
            <FlatList
                data={categories}
                keyExtractor={id => categories.id}
                renderItem={({ item }) => (
                    <View style={styles.category}>
                        <Image source={item.image} style={styles.categoryImage} />
                        <Text style={styles.categoryText}>{item.name}</Text>
                    </View>
                )}
                horizontal
                snapToAlignment={'center'}
            ></FlatList>

        </View>
    )
}

const styles = StyleSheet.create({
    categoriesScreen: {
        marginTop: 25,
    },
    categoryImage: {
        width: 50,
        height: 50,
        borderRadius: 100
    },
    category: {
        marginRight: 16,
        alignItems: 'center',
    },
    categoryText: {
        color:'grey',
        fontWeight:'bold',
        fontSize:10
    }
})