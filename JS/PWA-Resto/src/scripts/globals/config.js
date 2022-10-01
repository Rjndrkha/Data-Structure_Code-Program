const CONFIG = {
  KEY: '',
  BASE_URL: 'https://restaurant-api.dicoding.dev/',
  BASE_IMAGE_SMALL_URL: 'https://restaurant-api.dicoding.dev/images/small/',
  BASE_IMAGE_MEDIUM_URL: 'https://restaurant-api.dicoding.dev/images/medium/',
  BASE_IMAGE_LARGE_URL: 'https://restaurant-api.dicoding.dev/images/large/',
  IMAGE_DEFAULT_FOOD_URL: './images/foods.png',
  IMAGE_DEFAULT_DRINK_URL: './images/drinks.png',
  CACHE_NAME: new Date().toISOString(),
  DATABASE_NAME: 'resto-kuno-database',
  DATABASE_VERSION: 1,
  OBJECT_STORE_NAME: 'restaurants',
  X_AUTH_TOKEN: '12345',
};

export default CONFIG;
