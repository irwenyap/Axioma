export module Math.Vector3;

import std;

export namespace Math {

	template <typename T = float>
		requires std::is_floating_point_v<T>
	struct Vector3 {
		T x{};
		T y{};
		T z{};

		constexpr Vector3() noexcept = default;
		constexpr Vector3(T x, T y, T z) noexcept : x(x), y(y), z(z) {}
		constexpr explicit Vector3(T value) noexcept : x(value), y(value), z(value) {}
		constexpr Vector3(const Vector3&) noexcept = default;
		constexpr Vector3(Vector3&&) noexcept = default;
		constexpr ~Vector3() noexcept = default;
		constexpr Vector3& operator=(const Vector3&) noexcept = default;
		constexpr Vector3& operator=(Vector3&&) noexcept = default;

		constexpr Vector3& operator+=(const Vector3& rhs) noexcept {
			x += rhs.x; y += rhs.y; z += rhs.z;
			return *this;
		}

		constexpr Vector3& operator+=(T scalar) noexcept {
			x += scalar; y += scalar; z += scalar;
			return *this;
		}

		constexpr Vector3& operator-=(const Vector3& rhs) noexcept {
			x -= rhs.x; y -= rhs.y; z -= rhs.z;
			return *this;
		}

		constexpr Vector3& operator-=(T scalar) noexcept {
			x -= scalar; y -= scalar; z -= scalar;
			return *this;
		}

		[[nodiscard]] constexpr Vector3 operator-() const noexcept {
			return Vector3(-x, -y, -z);
		}

		[[nodiscard]] constexpr Vector3 operator+() const noexcept {
			return *this;
		}

		constexpr Vector3& operator*=(T scalar) noexcept {
			x *= scalar; y *= scalar; z *= scalar;
			return *this;
		}

		constexpr Vector3& operator*=(const Vector3& rhs) noexcept {
			x *= rhs.x; y *= rhs.y; z *= rhs.z;
			return *this;
		}

		constexpr Vector3& operator/=(T scalar) noexcept {
			x /= scalar; y /= scalar; z /= scalar;
			return *this;
		}

		constexpr Vector3& operator/=(const Vector3& rhs) noexcept {
			x /= rhs.x; y /= rhs.y; z /= rhs.z;
			return *this;
		}

		friend constexpr Vector3 operator+(Vector3 lhs, const Vector3& rhs) noexcept {
			lhs += rhs;
			return lhs;
		}

		friend constexpr Vector3 operator+(Vector3 lhs, T scalar) noexcept {
			lhs += scalar;
			return lhs;
		}

		friend constexpr Vector3 operator+(T scalar, Vector3 rhs) noexcept {
			rhs += scalar;
			return rhs;
		}

		friend constexpr Vector3 operator-(Vector3 lhs, const Vector3& rhs) noexcept {
			lhs -= rhs;
			return lhs;
		}

		friend constexpr Vector3 operator-(Vector3 lhs, T scalar) noexcept {
			lhs -= scalar;
			return lhs;
		}

		friend constexpr Vector3 operator-(T scalar, const Vector3& rhs) noexcept {
			return Vector3(scalar - rhs.x, scalar - rhs.y, scalar - rhs.z);
		}

		friend constexpr Vector3 operator*(Vector3 lhs, const Vector3& rhs) noexcept {
			lhs *= rhs;
			return lhs;
		}

		friend constexpr Vector3 operator*(Vector3 lhs, T scalar) noexcept {
			lhs *= scalar;
			return lhs;
		}

		friend constexpr Vector3 operator*(T scalar, Vector3 rhs) noexcept {
			rhs *= scalar;
			return rhs;
		}

		friend constexpr Vector3 operator/(Vector3 lhs, const Vector3& rhs) noexcept {
			lhs /= rhs;
			return lhs;
		}

		friend constexpr Vector3 operator/(Vector3 lhs, T scalar) noexcept {
			lhs /= scalar;
			return lhs;
		}

		friend constexpr Vector3 operator/(T scalar, const Vector3& rhs) noexcept {
			return Vector3(scalar / rhs.x, scalar / rhs.y, scalar / rhs.z);
		}

		constexpr bool operator==(const Vector3&) const noexcept = default;
		constexpr auto operator<=>(const Vector3&) const noexcept = default;

		constexpr T& operator[](std::size_t index) noexcept {
			return Data()[index];
		}

		constexpr const T& operator[](std::size_t index) const noexcept {
			return Data()[index];
		}

		[[nodiscard]] explicit constexpr operator T* () noexcept { return &x; }
		[[nodiscard]] explicit constexpr operator const T* () const noexcept { return &x; }

		friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
			os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
			return os;
		}

		[[nodiscard]] constexpr T* Data() noexcept {
			return &x;
		}

		[[nodiscard]] constexpr const T* Data() const noexcept {
			return &x;
		}

		[[nodiscard]] constexpr T SqrMagnitude() const noexcept {
			return x * x + y * y + z * z;
		}

		[[nodiscard]] constexpr T Dot(const Vector3& rhs) const noexcept {
			return x * rhs.x + y * rhs.y + z * rhs.z;
		}

		[[nodiscard]] constexpr Vector3 Cross(const Vector3& rhs) const noexcept {
			return Vector3(
				y * rhs.z - z * rhs.y,
				z * rhs.x - x * rhs.z,
				x * rhs.y - y * rhs.x
			);
		}

		[[nodiscard]] constexpr T Magnitude() const noexcept {
			return std::sqrt(SqrMagnitude());
		}

		constexpr void Normalize() noexcept {
			const T length = Magnitude();
			if (length != 0) {
				x /= length;
				y /= length;
				z /= length;
			}
		}

		[[nodiscard]] constexpr Vector3 Normalized() const noexcept {
			const T length = Magnitude();
			if (length != 0) {
				return Vector3(x / length, y / length, z / length);
			}
			return Vector3{};
		}
	};

	using Vector3f = Vector3<float>;
	using Vector3d = Vector3<double>;
}
