/// Returns the mapped value for the given key, or a provided default.
///
/// If the key exists in the map, its mapped value is returned. Otherwise,
/// the supplied default value is returned.
///
/// This function does not insert into the map and is useful when the mapped
/// type is not default-constructible.
///
/// \param Key The key to look up.
/// \param Default The value to return if the key is not found.
/// \returns The mapped value or the provided default.
template <typename U = std::remove_cv_t<ValueT>>
[[nodiscard]] ValueT lookup_or(const_arg_type_t<KeyT> Key,
                               U &&Default) const {
  if (const BucketT *Bucket = doFind(Key))
    return Bucket->getSecond();
  return Default;
}
